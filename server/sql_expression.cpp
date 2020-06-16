﻿/*
	Copyright (c) 2017 TOSHIBA Digital Solutions Corporation

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as
	published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "sql_expression_utils.h"
#include "sql_expression_base.h"
#include "sql_utils_vdbe.h"


SQLExprs::ExprCode::ExprCode() :
		type_(SQLType::START_EXPR),
		columnType_(TupleTypes::TYPE_NULL),
		input_(std::numeric_limits<uint32_t>::max()),
		column_(std::numeric_limits<uint32_t>::max()),
		value_(NULL),
		tableList_(NULL),
		output_(std::numeric_limits<uint32_t>::max()),
		aggrIndex_(std::numeric_limits<uint32_t>::max()),
		attributes_(0) {
}

SQLExprs::ExprType SQLExprs::ExprCode::getType() const {
	return type_;
}

void SQLExprs::ExprCode::setType(ExprType type) {
	type_ = type;
}

TupleColumnType SQLExprs::ExprCode::getColumnType() const {
	return columnType_;
}

void SQLExprs::ExprCode::setColumnType(TupleColumnType type) {
	columnType_ = type;
}

uint32_t SQLExprs::ExprCode::getInput() const {
	return input_;
}

void SQLExprs::ExprCode::setInput(uint32_t input) {
	input_ = input;
}

uint32_t SQLExprs::ExprCode::getColumnPos() const {
	return column_;
}

void SQLExprs::ExprCode::setColumnPos(uint32_t columnPos) {
	column_ = columnPos;
}

const TupleValue& SQLExprs::ExprCode::getValue() const {
	if (value_ == NULL) {
		return Constants::NULL_VALUE;
	}
	else {
		return *value_;
	}
}

void SQLExprs::ExprCode::setValue(
		SQLValues::ValueContext &cxt, const TupleValue &value) {
	TupleValue *dest = ALLOC_NEW(cxt.getAllocator()) TupleValue(value);

	*dest = SQLValues::ValueUtils::duplicateValue(cxt, value);

	value_ = dest;
}

void SQLExprs::ExprCode::importFromSyntax(
		SQLValues::ValueContext &cxt, const SyntaxExpr &src) {
	setType(src.op_);
	setColumnType(src.columnType_);
	setInput(src.inputId_);
	setColumnPos(src.columnId_);

	if (!SQLValues::ValueUtils::isNull(src.value_)) {
		setValue(cxt, src.value_);
	}
}

void SQLExprs::ExprCode::exportToSyntax(SyntaxExpr &dest) const {
	dest.op_ = getType();
	dest.columnType_ = getColumnType();
	dest.inputId_ = getInput();
	dest.columnId_ = getColumnPos();
	dest.value_ = getValue();
}

uint32_t SQLExprs::ExprCode::getAggregationIndex() const {
	return aggrIndex_;
}

void SQLExprs::ExprCode::setAggregationIndex(uint32_t index) {
	aggrIndex_ = index;
}

uint32_t SQLExprs::ExprCode::getAttributes() const {
	return attributes_;
}

void SQLExprs::ExprCode::setAttributes(uint32_t attributes) {
	attributes_ = attributes;
}

SQLExprs::ExprCode::TableEntry::TableEntry() :
		input_(0) {
}

const TupleValue SQLExprs::ExprCode::Constants::NULL_VALUE;


SQLExprs::Expression::Expression() :
		code_(NULL),
		planningCode_(NULL),
		child_(NULL),
		next_(NULL) {
}

SQLExprs::Expression::~Expression() {
}

void SQLExprs::Expression::initialize(
		ExprFactoryContext &cxt, const ExprCode &code) {
	assert(code_ == NULL);

	if (planningCode_ == NULL) {
		const Expression *baseExpr = cxt.getBaseExpression();
		if (baseExpr != NULL && &baseExpr->getCode() == &code) {
			code_ = &code;
		}
		else {
			code_ = ALLOC_NEW(cxt.getAllocator()) ExprCode(code);
		}
	}
	else {
		code_ = planningCode_;
	}
}

const SQLExprs::Expression& SQLExprs::Expression::child() const {
	assert(child_ != NULL);
	return *child_;
}

const SQLExprs::Expression& SQLExprs::Expression::next() const {
	assert(next_ != NULL);
	return *next_;
}

const SQLExprs::Expression* SQLExprs::Expression::findChild() const {
	return child_;
}

const SQLExprs::Expression* SQLExprs::Expression::findNext() const {
	return next_;
}

size_t SQLExprs::Expression::getChildCount() const {
	return getChildCount(*this);
}

const SQLExprs::ExprCode& SQLExprs::Expression::getCode() const {
	assert(code_ != NULL);
	return *code_;
}

TupleValue SQLExprs::Expression::asColumnValue(const TupleValue &value) const {
	const TupleColumnType type = getCode().getColumnType();
	assert(!SQLValues::TypeUtils::isNull(type));

	if (SQLValues::ValueUtils::isNull(value)) {
		if (!SQLValues::TypeUtils::isNullable(type) &&
				!SQLValues::TypeUtils::isAny(type)) {
			GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL_INVALID_INPUT, "");
		}
		return value;
	}

	return SQLValues::ValuePromoter(
			SQLValues::TypeUtils::toNonNullable(type))(value);
}

bool SQLExprs::Expression::isPlannable() const {
	return (planningCode_ != NULL);
}

SQLExprs::ExprCode& SQLExprs::Expression::getPlanningCode() {
	assert(isPlannable());
	return *planningCode_;
}

void SQLExprs::Expression::addChild(Expression *expr) {
	for (ModIterator it(*this);; it.next()) {
		if (!it.exists()) {
			it.append(*expr);
			break;
		}
	}
}

SQLExprs::Expression& SQLExprs::Expression::importFrom(
		ExprFactoryContext &cxt, const InOption &option) {
	if (option.syntaxExpr_ != NULL) {
		return importFromSyntax(cxt, *option.syntaxExpr_, option);
	}
	else if (option.byteStream_ != NULL) {
		return importFromStream(cxt, *option.byteStream_, option);
	}
	else if (option.stream_ != NULL) {
		return importFromStream(cxt, *option.stream_, option);
	}
	else {
		assert(false);
		GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL, "");
	}
}

void SQLExprs::Expression::exportTo(const OutOption &option) const {
	if (option.syntaxExprRef_ != NULL) {
		*option.syntaxExprRef_ = ALLOC_NEW(option.getAllocator()) SyntaxExpr(
				exportToSyntax(option));
	}
	else if (option.byteStream_ != NULL) {
		exportToStream(*option.byteStream_, option);
	}
	else if (option.stream_ != NULL) {
		exportToStream(*option.stream_, option);
	}
	else {
		assert(false);
		GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL, "");
	}
}

void SQLExprs::Expression::setPlanningCode(ExprCode *code) {
	assert(code_ == NULL && planningCode_ == NULL);
	planningCode_ = code;
}

SQLExprs::Expression& SQLExprs::Expression::importFromSyntax(
		ExprFactoryContext &cxt, const SyntaxExpr &src, const InOption &option) {
	ExprCode code;
	code.importFromSyntax(option.valueCxt_, src);
	resolvePlaceholder(option.valueCxt_, code, option);

	Expression &expr = cxt.getFactory().create(cxt, code);
	expr.getPlanningCode() = code;

	Expression::ModIterator destIt(expr);
	const bool listing =
			isListingSyntaxExpr(code.getType(), cxt.getFactory(), src);
	do {
		if (listing) {
			if (src.next_ == NULL) {
				break;
			}
			for (SyntaxExprRefList::const_iterator it = src.next_->begin();
					it != src.next_->end(); ++it) {
				assert(*it != NULL);
				destIt.append(importFromSyntax(cxt, **it, option));
			}
		}
		else {
			if (src.left_ == NULL) {
				break;
			}
			destIt.append(importFromSyntax(cxt, *src.left_, option));

			if (src.right_ == NULL) {
				break;
			}
			destIt.append(importFromSyntax(cxt, *src.right_, option));
		}
	}
	while (false);

	return expr;
}

SQLExprs::SyntaxExpr SQLExprs::Expression::exportToSyntax(
		const OutOption &option) const {
	util::StackAllocator &alloc = option.getAllocator();

	SyntaxExpr dest(alloc);
	getCode().exportToSyntax(dest);

	const bool listing = isListingSyntaxExpr(
			getCode().getType(), option.getFactory(), *this);
	size_t nonListingCount = 0;

	for (Iterator it(*this); it.exists(); it.next()) {
		SyntaxExpr *sub = ALLOC_NEW(alloc) SyntaxExpr(
				it.get().exportToSyntax(option));
		if (listing) {
			if (dest.next_ == NULL) {
				dest.next_ = ALLOC_NEW(alloc) SyntaxExprRefList(alloc);
			}
			dest.next_->push_back(sub);
		}
		else {
			assert(nonListingCount < 2);
			if (nonListingCount == 0) {
				dest.left_ = sub;
			}
			else {
				dest.right_ = sub;
			}
			++nonListingCount;
		}
	}

	return dest;
}

template<typename S>
SQLExprs::Expression& SQLExprs::Expression::importFromStream(
		ExprFactoryContext &cxt, S &stream, const InOption &option) {
	VarContext &varCxt = option.getVarContext();

	util::ObjectCoder::Type subType;
	if (stream.peekType(subType, util::ObjectCoder::Attribute()) &&
			subType != util::ObjectCoder::TYPE_OBJECT) {
		TupleValue value;
		TupleValue::coder(util::ObjectCoder(), &varCxt).decode(stream, value);
		return ExprRewriter::createConstExpr(cxt, value);
	}

	typename S::ObjectScope objectScope(
			stream, util::ObjectCoder::Attribute());
	S &subStream = objectScope.stream();

	Expression *expr;
	{
		ExprCode code;
		TupleValue::coder(
				util::ObjectCoder::withAllocator(
						cxt.getAllocator()), &varCxt).decode(subStream, code);

		if (code.getType() == SQLType::EXPR_TUPLE_COLUMN) {
			code.setType(SQLType::EXPR_COLUMN);
			if (code.getInput() != std::numeric_limits<uint32_t>::max()) {
				code.setInput(code.getInput() - 1);
			}
		}
		expr = &cxt.getFactory().create(cxt, code);
	}

	util::ObjectCoder::Type opListType;
	if (subStream.peekType(opListType, Constants::STREAM_ATTR_OP_LIST) &&
			opListType == util::ObjectCoder::TYPE_NULL) {
		return *expr;
	}

	size_t count;
	typename S::ListScope listScope(
			subStream, count, Constants::STREAM_ATTR_OP_LIST);

	ModIterator it(*expr);
	for (size_t i = count; i > 0; i--) {
		it.append(importFromStream(cxt, listScope.stream(), option));
	}

	return *expr;
}

template<typename S>
void SQLExprs::Expression::exportToStream(
		S &stream, const OutOption &option) const {

	typename S::ObjectScope objectScope(
			stream, util::ObjectCoder::Attribute());
	S &subStream = objectScope.stream();

	TupleValue::coder(util::ObjectCoder(), NULL).encode(subStream, code_);

	const size_t count = getChildCount();
	typename S::ListScope listScope(
			subStream, count, Constants::STREAM_ATTR_OP_LIST);

	Expression *last = child_;
	for (size_t i = count; i > 0; i--) {
		last->exportToStream(listScope.stream(), option);
		last = last->next_;
	}
}

void SQLExprs::Expression::resolvePlaceholder(
		SQLValues::ValueContext &cxt, ExprCode &code, const InOption &option) {
	if (option.parameterList_ == NULL ||
			code.getType() != SQLType::EXPR_PLACEHOLDER) {
		return;
	}

	const uint32_t index = code.getColumnPos();
	if (index >= option.parameterList_->size()) {
		GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL_INVALID_EXPRESSION,
				"Parameter index out of range (index=" << index << ")");
	}

	code.setType(SQLType::EXPR_CONSTANT);
	code.setValue(cxt, (*option.parameterList_)[index]);
}

template<typename E>
bool SQLExprs::Expression::isListingSyntaxExpr(
		ExprType type, const ExprFactory &factory, const E &expr) {
	return 
			(SQLType::START_AGG < type && type < SQLType::END_AGG) ||
			(SQLType::START_FUNC < type && type < SQLType::END_FUNC) ||
			getChildCount(expr) > 2 ||
			(factory.getSpec(type).flags_ & ExprSpec::FLAG_ARGS_LISTING) != 0;
}

size_t SQLExprs::Expression::getChildCount(const SyntaxExpr &expr) {
	if (expr.next_ != NULL) {
		return expr.next_->size();
	}
	else if (expr.left_ != NULL) {
		return (expr.right_ != NULL ? 2 : 1);
	}
	return 0;
}

size_t SQLExprs::Expression::getChildCount(const Expression &expr) {
	size_t count = 0;
	for (Iterator it(expr); it.exists(); it.next()) {
		++count;
	}
	return count;
}


SQLExprs::Expression::InOption::InOption(SQLValues::ValueContext &valueCxt) :
		valueCxt_(valueCxt),
		syntaxExpr_(NULL),
		byteStream_(NULL),
		stream_(NULL),
		parameterList_(NULL) {
}

SQLExprs::VarContext& SQLExprs::Expression::InOption::getVarContext() const {
	return valueCxt_.getVarContext();
}

void SQLExprs::Expression::InOption::setStream(ObjectByteInStream &stream) {
	byteStream_ = &stream;
}

void SQLExprs::Expression::InOption::setStream(
		util::AbstractObjectInStream &stream) {
	stream_ = &stream;
}


SQLExprs::Expression::OutOption::OutOption(
		util::StackAllocator *alloc, const ExprFactory &factory) :
		alloc_(alloc),
		factory_(&factory),
		syntaxExprRef_(NULL),
		byteStream_(NULL),
		stream_(NULL) {
}

util::StackAllocator& SQLExprs::Expression::OutOption::getAllocator() const {
	assert(alloc_ != NULL);
	return *alloc_;
}

const SQLExprs::ExprFactory&
SQLExprs::Expression::OutOption::getFactory() const {
	assert(factory_ != NULL);
	return *factory_;
}

void SQLExprs::Expression::OutOption::setStream(
		ObjectByteOutStream &stream) {
	byteStream_ = &stream;
}

void SQLExprs::Expression::OutOption::setStream(
		util::AbstractObjectOutStream &stream) {
	stream_ = &stream;
}


SQLExprs::Expression::Iterator::Iterator(const Expression &expr) :
		cur_(expr.child_) {
}

const SQLExprs::Expression& SQLExprs::Expression::Iterator::get() const {
	assert(exists());
	return *cur_;
}

bool SQLExprs::Expression::Iterator::exists() const {
	return (cur_ != NULL);
}

void SQLExprs::Expression::Iterator::next() {
	cur_ = cur_->next_;
}


SQLExprs::Expression::ModIterator::ModIterator(Expression &expr) :
		parent_(&expr),
		prev_(NULL),
		cur_(expr.child_) {
}

SQLExprs::Expression& SQLExprs::Expression::ModIterator::get() const {
	assert(exists());
	return *cur_;
}

bool SQLExprs::Expression::ModIterator::exists() const {
	return (cur_ != NULL);
}

void SQLExprs::Expression::ModIterator::next() {
	assert(exists());
	prev_ = cur_;
	cur_ = cur_->next_;
}

void SQLExprs::Expression::ModIterator::insert(Expression &expr) {
	assert(expr.next_ == NULL);
	if (prev_ == NULL) {
		assert(parent_->child_ == cur_);
		parent_->child_ = &expr;
	}
	else {
		prev_->next_ = &expr;
	}
	expr.next_ = cur_;
	cur_ = &expr;
}

void SQLExprs::Expression::ModIterator::append(Expression &expr) {
	insert(expr);
	next();
}

void SQLExprs::Expression::ModIterator::remove() {
	assert(exists());
	if (prev_ == NULL) {
		assert(parent_->child_ == cur_);
		parent_->child_ = cur_->next_;
	}
	else {
		prev_->next_ = cur_->next_;
	}

	Expression *next = cur_->next_;
	cur_->next_ = NULL;
	cur_ = next;
}


const util::ObjectCoder::Attribute
SQLExprs::Expression::Constants::STREAM_ATTR_OP_LIST("opList");


bool SQLExprs::FunctionValueUtils::isSpaceChar(util::CodePoint c) const {
	return SQLVdbeUtils::VdbeUtils::isSpaceChar(c);
}


SQLExprs::NormalFunctionContext::NormalFunctionContext(
		SQLValues::ValueContext &valueCxt) :
		base_(NULL),
		valueCxt_(valueCxt) {
}

SQLExprs::ExprContext&
SQLExprs::NormalFunctionContext::getBase() {
	if (base_ == NULL) {
		handleBaseNotFound();
	}
	return *base_;
}

void SQLExprs::NormalFunctionContext::setBase(ExprContext *base) {
	base_ = base;
}

util::FalseType SQLExprs::NormalFunctionContext::initializeResultWriter(
		uint64_t initialCapacity) {
	static_cast<void>(initialCapacity);
	return util::FalseType();
}

const SQLExprs::NormalFunctionContext::ValueUtilsType&
SQLExprs::NormalFunctionContext::getValueUtils() {
	return valueUtils_;
}

int64_t SQLExprs::NormalFunctionContext::getCurrentTimeMillis() {
	return valueCxt_.getCurrentTimeMillis();
}

util::TimeZone SQLExprs::NormalFunctionContext::getTimeZone() {
	return valueCxt_.getTimeZone();
}

void SQLExprs::NormalFunctionContext::applyDateTimeOption(
		util::DateTime::ZonedOption &option) const {
	return SQLValues::ValueUtils::applyDateTimeOption(option);
}

void SQLExprs::NormalFunctionContext::applyDateTimeOption(
		util::DateTime::Option &option) const {
	return SQLValues::ValueUtils::applyDateTimeOption(option);
}

void SQLExprs::NormalFunctionContext::handleBaseNotFound() {
	assert(false);
	GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL, "");
}


SQLExprs::ExprContext::ExprContext(
		const SQLValues::ValueContext::Source &source) :
		valueCxt_(source),
		funcCxt_(valueCxt_),
		entryList_(valueCxt_.getAllocator()),
		activeInput_(std::numeric_limits<uint32_t>::max()),
		aggrTuple_(NULL) {
}

SQLExprs::ExprContext::operator SQLValues::ValueContext&() {
	return valueCxt_;
}

SQLValues::ValueContext& SQLExprs::ExprContext::getValueContext() {
	return valueCxt_;
}

SQLExprs::NormalFunctionContext&
SQLExprs::ExprContext::getFunctionContext() {
	return funcCxt_;
}

util::StackAllocator& SQLExprs::ExprContext::getAllocator() {
	return valueCxt_.getAllocator();
}

const SQLExprs::TupleColumn& SQLExprs::ExprContext::getReaderColumn(
		uint32_t index, uint32_t pos) {
	Entry &entry = entryList_[index];
	assert(entry.columnList_ != NULL);
	return (*entry.columnList_)[pos];
}

SQLExprs::TupleListReader& SQLExprs::ExprContext::getReader(uint32_t index) {
	Entry &entry = entryList_[index];
	assert(entry.reader_ != NULL);
	return *entry.reader_;
}

SQLExprs::ReadableTuple SQLExprs::ExprContext::getReadableTuple(
		uint32_t index) {
	Entry &entry = entryList_[index];
	if (entry.readableTuple_ == NULL) {
		assert(entry.reader_ != NULL);
		return entry.reader_->get();
	}
	else {
		return *entry.readableTuple_;
	}
}

void SQLExprs::ExprContext::setReader(
		uint32_t index, TupleListReader &reader,
		const TupleColumnList *columnList) {
	Entry &entry = prepareEntry(index);

	if (columnList != NULL) {
		entry.columnList_ = columnList;
	}

	entry.reader_ = &reader;
	entry.readableTuple_ = NULL;
}

void SQLExprs::ExprContext::setReadableTuple(
		uint32_t index, const ReadableTuple &tuple) {
	Entry &entry = prepareEntry(index);

	if (entry.readableTuple_ == NULL) {
		if (entry.readableTupleStorage_ == NULL) {
			entry.readableTupleStorage_ =
					ALLOC_NEW(getAllocator()) ReadableTuple(tuple);
		}
		entry.readableTuple_ = entry.readableTupleStorage_;
	}
	*entry.readableTuple_ = tuple;
}

SQLValues::ArrayTuple* SQLExprs::ExprContext::getArrayTuple(uint32_t index) {
	Entry &entry = entryList_[index];
	return entry.arrayTuple_;
}

void SQLExprs::ExprContext::setArrayTuple(
		uint32_t index, SQLValues::ArrayTuple *tuple) {
	Entry &entry = prepareEntry(index);
	entry.arrayTuple_ = tuple;
}

uint32_t SQLExprs::ExprContext::getActiveInput() {
	assert(activeInput_ != std::numeric_limits<uint32_t>::max());
	return activeInput_;
}

void SQLExprs::ExprContext::setActiveInput(uint32_t index) {
	activeInput_ = index;
}

int64_t SQLExprs::ExprContext::updateTupleId(uint32_t index) {
	Entry &entry = entryList_[index];
	return ++entry.lastTupleId_;
}

int64_t SQLExprs::ExprContext::getLastTupleId(uint32_t index) {
	Entry &entry = entryList_[index];
	return entry.lastTupleId_;
}

void SQLExprs::ExprContext::setLastTupleId(uint32_t index, int64_t id) {
	Entry &entry = prepareEntry(index);
	entry.lastTupleId_ = id;
}

void SQLExprs::ExprContext::setAggregationTuple(
		SQLValues::ArrayTuple &aggrTuple) {
	aggrTuple_ = &aggrTuple;
}

TupleValue SQLExprs::ExprContext::getAggregationValue(uint32_t index) {
	if (aggrTuple_ == NULL) {
		assert(false);
		GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL, "");
	}
	return aggrTuple_->get(index);
}

void SQLExprs::ExprContext::setAggregationValue(
		uint32_t index, const TupleValue &value) {
	if (aggrTuple_ == NULL) {
		assert(false);
		GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL, "");
	}
	return aggrTuple_->set(index, valueCxt_, value);
}

SQLExprs::ExprContext::Entry&
SQLExprs::ExprContext::prepareEntry(uint32_t index) {
	while (index >= entryList_.size()) {
		entryList_.push_back(Entry());
	}
	return entryList_[index];
}


SQLExprs::ExprContext::Entry::Entry() :
		reader_(NULL),
		columnList_(NULL),
		readableTuple_(NULL),
		readableTupleStorage_(NULL),
		arrayTuple_(NULL),
		lastTupleId_(0) {
}


SQLExprs::ExprSpec::ExprSpec() :
		outType_(TupleTypes::TYPE_NULL),
		flags_(0),
		distinctExprType_(SQLType::START_EXPR) {
}

bool SQLExprs::ExprSpec::isAggregation() const {
	return !SQLValues::TypeUtils::isNull(aggrList_[0].typeList_[0]);
}


SQLExprs::ExprSpec::In::In() :
		flags_(0) {
	std::fill(
			typeList_, typeList_ + sizeof(typeList_) / sizeof(*typeList_),
			static_cast<TupleColumnType>(TupleTypes::TYPE_NULL));
}


SQLExprs::ExprFactory::ExprFactory() {
}

const SQLExprs::ExprFactory& SQLExprs::ExprFactory::getDefaultFactory() {
	return DefaultExprFactory::getFactory();
}

SQLExprs::Expression& SQLExprs::ExprFactory::create(
		ExprFactoryContext &cxt, ExprType type) const {
	ExprCode code;
	code.setType(type);
	return create(cxt, code);
}


SQLExprs::ExprFactoryContext::ExprFactoryContext(util::StackAllocator &alloc) :
		alloc_(alloc),
		factory_(&ExprFactory::getDefaultFactory()),
		scopedEntry_(&topScopedEntry_),
		inputList_(alloc),
		inputColumnList_(alloc),
		nullableList_(alloc),
		aggrTypeList_(alloc),
		nextAggrIndex_(0) {
}

util::StackAllocator& SQLExprs::ExprFactoryContext::getAllocator() {
	return alloc_;
}

const SQLExprs::ExprFactory& SQLExprs::ExprFactoryContext::getFactory() {
	if (factory_ == NULL) {
		return ExprFactory::getDefaultFactory();
	}
	return *factory_;
}

void SQLExprs::ExprFactoryContext::setFactory(const ExprFactory *factory) {
	factory_ = factory;
}

void SQLExprs::ExprFactoryContext::clearInputTypes() {
	inputList_.clear();
	inputColumnList_.clear();
	nullableList_.clear();
}

TupleColumnType SQLExprs::ExprFactoryContext::getInputType(
		uint32_t index, uint32_t pos) {
	if (index >= inputList_.size()) {
		GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL_INVALID_INPUT, "");
	}
	const TypeList &typeList = inputList_[index];

	if (pos >= typeList.size()) {
		GS_THROW_USER_ERROR(GS_ERROR_SQL_PROC_INTERNAL_INVALID_INPUT, "");
	}
	return typeList[pos];
}

void SQLExprs::ExprFactoryContext::setInputType(
		uint32_t index, uint32_t pos, TupleColumnType type) {
	while (index >= inputList_.size()) {
		inputList_.push_back(TypeList(alloc_));
	}

	TypeList &typeList = inputList_[index];
	while (pos >= typeList.size()) {
		typeList.push_back(TupleTypes::TYPE_NULL);
	}

	if (index < inputColumnList_.size()) {
		inputColumnList_[index].clear();
	}

	typeList[pos] = type;
}

TupleColumnType SQLExprs::ExprFactoryContext::getUnifiedInputType(
		uint32_t pos) {
	TupleColumnType type = TupleTypes::TYPE_NULL;

	for (InputList::iterator it = inputList_.begin();
			it != inputList_.end(); ++it) {
		const TupleColumnType elemType = (*it)[pos];
		if (it == inputList_.begin()) {
			type = elemType;
		}
		else {
			type = SQLValues::TypeUtils::findPromotionType(
					type, elemType, true);
		}

		if (SQLValues::TypeUtils::isNull(type)) {
			break;
		}
	}

	assert(!SQLValues::TypeUtils::isNull(type));
	return type;
}

TupleList::Column SQLExprs::ExprFactoryContext::getInputColumn(
		uint32_t index, uint32_t pos) {
	while (index >= inputColumnList_.size()) {
		inputColumnList_.push_back(TupleColumnList(alloc_));
	}

	TupleColumnList &list = inputColumnList_[index];
	if (pos >= list.size()) {
		list.clear();

		const TypeList &typeList = inputList_[index];

		TupleList::Info info;
		info.columnTypeList_ = &typeList[0];
		info.columnCount_ = typeList.size();

		list.resize(info.columnCount_);
		info.getColumns(&list[0], list.size());
	}

	return list[pos];
}

uint32_t SQLExprs::ExprFactoryContext::getInputCount() {
	return static_cast<uint32_t>(inputList_.size());
}

uint32_t SQLExprs::ExprFactoryContext::getInputColumnCount(uint32_t index) {
	assert(index < inputList_.size());

	const TypeList &typeList = inputList_[index];
	return static_cast<uint32_t>(typeList.size());
}

bool SQLExprs::ExprFactoryContext::isInputNullable(uint32_t index) {
	assert(index < nullableList_.size());
	return nullableList_[index];
}

void SQLExprs::ExprFactoryContext::setInputNullable(
		uint32_t index, bool nullable) {
	while (index >= nullableList_.size()) {
		nullableList_.push_back(false);
	}
	nullableList_[index] = nullable;
}

uint32_t SQLExprs::ExprFactoryContext::getAggregationColumnCount() {
	const TypeList *ref = scopedEntry_->aggrTypeListRef_;
	if (ref != NULL) {
		return static_cast<uint32_t>(ref->size());
	}
	return nextAggrIndex_;
}

TupleColumnType SQLExprs::ExprFactoryContext::getAggregationColumnType(
		uint32_t index) {
	const TypeList *ref = scopedEntry_->aggrTypeListRef_;
	const TypeList &typeList = (ref == NULL ? aggrTypeList_ : *ref);

	assert(index < typeList.size());
	return typeList[index];
}

uint32_t SQLExprs::ExprFactoryContext::addAggregationColumn(
		TupleColumnType type) {
	assert(scopedEntry_->aggrTypeListRef_ == NULL);
	assert(!SQLValues::TypeUtils::isNull(type));

	while (nextAggrIndex_ >= aggrTypeList_.size()) {
		aggrTypeList_.push_back(TupleTypes::TYPE_NULL);
	}

	const uint32_t aggrIndex = nextAggrIndex_;
	TupleColumnType &destType = aggrTypeList_[aggrIndex];

	assert(SQLValues::TypeUtils::isNull(destType) || destType == type);
	destType = type;

	++nextAggrIndex_;
	return aggrIndex;
}

void SQLExprs::ExprFactoryContext::clearAggregationColumns() {
	assert(scopedEntry_->aggrTypeListRef_ == NULL);
	assert(aggrTypeList_.size() == nextAggrIndex_);
	nextAggrIndex_ = 0;
}

bool SQLExprs::ExprFactoryContext::isPlanning() {
	return scopedEntry_->planning_;
}

void SQLExprs::ExprFactoryContext::setPlanning(bool planning) {
	scopedEntry_->planning_ = planning;
}

SQLType::AggregationPhase SQLExprs::ExprFactoryContext::getAggregationPhase(
		bool forSrc) {
	return (forSrc ? scopedEntry_->srcAggrPhase_ : scopedEntry_->destAggrPhase_);
}

void SQLExprs::ExprFactoryContext::setAggregationPhase(
		bool forSrc, AggregationPhase aggrPhase) {
	(forSrc ? scopedEntry_->srcAggrPhase_ : scopedEntry_->destAggrPhase_) =
			aggrPhase;
}

void SQLExprs::ExprFactoryContext::setAggregationTypeListRef(
		const util::Vector<TupleColumnType> *typeListRef) {
	scopedEntry_->aggrTypeListRef_ = typeListRef;
}

const SQLExprs::Expression* SQLExprs::ExprFactoryContext::getBaseExpression() {
	return scopedEntry_->baseExpr_;
}

void SQLExprs::ExprFactoryContext::setBaseExpression(const Expression *expr) {
	scopedEntry_->baseExpr_ = expr;
}

SQLExprs::ExprFactoryContext::ScopedEntry::ScopedEntry() :
		planning_(true),
		srcAggrPhase_(SQLType::END_AGG_PHASE),
		destAggrPhase_(SQLType::END_AGG_PHASE),
		aggrTypeListRef_(NULL),
		baseExpr_(NULL) {
}

SQLExprs::ExprFactoryContext::Scope::Scope(ExprFactoryContext &cxt) :
		cxt_(cxt),
		curScopedEntry_(*cxt.scopedEntry_),
		prevScopedEntry_(cxt.scopedEntry_) {
	cxt_.scopedEntry_ = &curScopedEntry_;
}

SQLExprs::ExprFactoryContext::Scope::~Scope() {
	cxt_.scopedEntry_ = prevScopedEntry_;
}

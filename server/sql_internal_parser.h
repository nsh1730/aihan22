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
/**
 * @file   lemon-template.cpp
 *
 * @brief  C++ Driver template for the LEMON parser generator.
 *         Just ported into C++ style.
 *
 */

#ifndef LEMPAR_CPP_SQLParser_GENERATED_HPP
#define LEMPAR_CPP_SQLParser_GENERATED_HPP

#ifdef _WIN32
#pragma warning(disable:4065)
#endif
/* First off, code is included that follows the "include" declaration
 ** in the input grammar file. */

#include "sql_internal_parser_token.h"

#include "sql_parser_define.h"
#include "sql_parser.h"
#include "sql_processor.h" 
#include "util/container.h"
#include "util/time.h"

#include <vector>
#include <stdexcept>

#ifdef _WIN32
#define atoll atol
#endif

/*
** Disable all error recovery processing in the parser push-down
** automaton.
*/
#define YYNOERRORRECOVERY 1

#define PRINT(...)

#define SQLPARSER_CONTEXT (parser)
#define SQLPARSER_ALLOCATOR (SQLPARSER_CONTEXT->getSQLAllocator())
#define SQLPARSER_NEW SQL_PARSER_ALLOC_NEW(SQLPARSER_ALLOCATOR)
#define SQLPARSER_DELETE(x) SQL_PARSER_ALLOC_DELETE(SQLPARSER_ALLOCATOR, x)
#define SQLPARSER_SAFE_DELETE(x) SQL_PARSER_ALLOC_SAFE_DELETE(SQLPARSER_ALLOCATOR,x)

#define SQL_PARSER_THROW_ERROR(errorCode, token, message) \
	do { \
		size_t line = 0; \
		size_t column = 0; \
		SyntaxTree::countLineAndColumnFromToken(parser->inputSql_, token, line, column); \
		GS_THROW_USER_ERROR(errorCode, \
			message << " (line=" << line << ", column=" << column << ")"); \
	} \
	while (false)

typedef SyntaxTree::Expr Expr;
typedef SyntaxTree::ExprList ExprList;
typedef SyntaxTree::Select Select;
typedef SyntaxTree::QualifiedName QualifiedName;

struct LikeOp {
	SQLToken operator_;		
	bool existNot_;			
};

struct IntervalOption {
	int64_t value_;			
	int64_t unit_;			
};

#include <iostream>

/* Next is all token values, in a form suitable for use by makeheaders.
 ** This section will be null unless lemon is run with the -m switch.
 */
/*
 ** These constants (all generated automatically by the parser generator)
 ** specify the various kinds of tokens (terminals) that the parser
 ** understands.
 **
 ** Each symbol here is a terminal symbol in the grammar.
 */

/* Make sure the INTERFACE macro is defined.
 */
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
 ** various aspects of the generated parser.
 **    SQLParser_YYCODETYPE         is the data type used for storing terminal
 **                       and nonterminal numbers.  "unsigned char" is
 **                       used if there are fewer than 250 terminals
 **                       and nonterminals.  "int" is used otherwise.
 **    SQLParser_YYNOCODE           is a number of type SQLParser_YYCODETYPE which corresponds
 **                       to no legal terminal or nonterminal number.  This
 **                       number is used to fill in empty slots of the hash
 **                       table.
 **    SQLParser_YYFALLBACK         If defined, this indicates that one or more tokens
 **                       have fall-back values which should be used if the
 **                       original value of the token will not parse.
 **    SQLParser_YYACTIONTYPE       is the data type used for storing terminal
 **                       and nonterminal numbers.  "unsigned char" is
 **                       used if there are fewer than 250 rules and
 **                       states combined.  "int" is used otherwise.
 **    SQLParserTOKENTYPE     is the data type used for minor tokens given
 **                       directly to the parser from the tokenizer.
 **    SQLParser_YYMINORTYPE        is the data type used for all minor tokens.
 **                       This is typically a union of many types, one of
 **                       which is SQLParserTOKENTYPE.  The entry in the union
 **                       for base tokens is called "yy0".
 **    SQLParser_YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
 **                       zero the stack is dynamically sized using realloc()
 **    SQLParserARG_SDECL     A static variable declaration for the %extra_argument
 **    SQLParserARG_PDECL     A parameter declaration for the %extra_argument
 **    SQLParser_YYNSTATE           the combined number of states.
 **    SQLParser_YYNRULE            the number of rules in the grammar
 **    SQLParser_YYERRORSYMBOL      is the code number of the error symbol.  If not
 **                       defined, then do no error processing.
 */
#define SQLParser_YYCODETYPE unsigned short int
#define SQLParser_YYNOCODE 264
#define SQLParser_YYACTIONTYPE unsigned short int
#define SQLParser_YYWILDCARD 102
#define SQLParserTOKENTYPE SQLToken
typedef union {
  int yyinit;
  SQLParserTOKENTYPE yy0;
  SyntaxTree::TableColumn* yy12;
  SyntaxTree::TableColumnList* yy18;
  Expr* yy60;
  SyntaxTree::SetOp yy69;
  uint8_t yy78;
  SyntaxTree::WindowOption* yy115;
  SyntaxTree::Set* yy158;
  SyntaxTree::AggrOpt yy168;
  SQLType::JoinType yy173;
  SyntaxTree::ColumnInfo* yy232;
  ExprList* yy294;
  QualifiedName* yy295;
  SyntaxTree::CreateIndexOption * yy329;
  bool yy371;
  int32_t yy428;
  SyntaxTree::PartitioningOption* yy437;
  struct LikeOp yy472;
  SyntaxTree::Select* yy474;
  struct IntervalOption yy482;
} SQLParser_YYMINORTYPE;
#ifndef SQLParser_YYSTACKDEPTH
#define SQLParser_YYSTACKDEPTH 2000
#endif
#define SQLParserARG_SDECL SQLParserContext* parser
#define SQLParserARG_PDECL ,SQLParserContext* parser
#define SQLParserARG_STORE this->parser = parser
#define SQLParser_YYNSTATE 610
#define SQLParser_YYNRULE 276
#define SQLParser_YYFALLBACK 1
#define SQLParser_YY_NO_ACTION      (SQLParser_YYNSTATE+SQLParser_YYNRULE+2)
#define SQLParser_YY_ACCEPT_ACTION  (SQLParser_YYNSTATE+SQLParser_YYNRULE+1)
#define SQLParser_YY_ERROR_ACTION   (SQLParser_YYNSTATE+SQLParser_YYNRULE)

/* The yyzerominor constant is used to initialize instances of
 ** SQLParser_YYMINORTYPE objects to zero. */
static const SQLParser_YYMINORTYPE SQLParser_yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
 ** otherwise.
 **
 ** Applications can choose to define yytestcase() in the %include section
 ** to a macro that can assist in verifying code coverage.  For production
 ** code the yytestcase() macro should be turned off.  But it is useful
 ** for testing.
 */
#ifndef yytestcase
# define yytestcase(X)
#endif

/*!
 * @brief SQLParser
 *
 */
namespace lemon_SQLParser {

	/*!
	 * @brief SQLParser parser main
	 *
	 */
	class SQLParser {

		/* Next are the tables used to determine what action to take based on the
		 ** current state and lookahead token.  These tables are used to implement
		 ** functions that take a state number and lookahead value and return an
		 ** action integer.
		 **
		 ** Suppose the action integer is N.  Then the action is determined as
		 ** follows
		 **
		 **   0 <= N < SQLParser_YYNSTATE                  Shift N.  That is, push the lookahead
		 **                                      token onto the stack and goto state N.
		 **
		 **   SQLParser_YYNSTATE <= N < SQLParser_YYNSTATE+SQLParser_YYNRULE   Reduce by rule N-SQLParser_YYNSTATE.
		 **
		 **   N == SQLParser_YYNSTATE+SQLParser_YYNRULE              A syntax error has occurred.
		 **
		 **   N == SQLParser_YYNSTATE+SQLParser_YYNRULE+1            The parser accepts its input.
		 **
		 **   N == SQLParser_YYNSTATE+SQLParser_YYNRULE+2            No such action.  Denotes unused
		 **                                      slots in the yy_action[] table.
		 **
		 ** The action table is constructed as a single large table named yy_action[].
		 ** Given state S and lookahead X, the action is computed as
		 **
		 **      yy_action[ yy_shift_ofst[S] + X ]
		 **
		 ** If the index value yy_shift_ofst[S]+X is out of range or if the value
		 ** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
		 ** is equal to SQLParser_YY_SHIFT_USE_DFLT, it means that the action is not in the table
		 ** and that yy_default[S] should be used instead.
		 **
		 ** The formula above is for computing the action when the lookahead is
		 ** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
		 ** a reduce action) then the yy_reduce_ofst[] array is used in place of
		 ** the yy_shift_ofst[] array and SQLParser_YY_REDUCE_USE_DFLT is used in place of
		 ** SQLParser_YY_SHIFT_USE_DFLT.
		 **
		 ** The following are the tables generated in this section:
		 **
		 **  yy_action[]        A single table containing all actions.
		 **  yy_lookahead[]     A table containing the lookahead for each entry in
		 **                     yy_action.  Used to detect hash collisions.
		 **  yy_shift_ofst[]    For each state, the offset into yy_action for
		 **                     shifting terminals.
		 **  yy_reduce_ofst[]   For each state, the offset into yy_action for
		 **                     shifting non-terminals after a reduce.
		 **  yy_default[]       Default action for each state.
		 */

#define SQLParser_YY_ACTTAB_COUNT (1350)
#define SQLParser_YY_SHIFT_USE_DFLT (-141)
#define SQLParser_YY_SHIFT_COUNT (442)
#define SQLParser_YY_SHIFT_MIN   (-140)
#define SQLParser_YY_SHIFT_MAX   (1266)
#define SQLParser_YY_REDUCE_USE_DFLT (-179)
#define SQLParser_YY_REDUCE_COUNT (288)
#define SQLParser_YY_REDUCE_MIN   (-178)
#define SQLParser_YY_REDUCE_MAX   (1113)
#define SQLParser_YYNFALLBACK  (102)

		static const SQLParser_YYACTIONTYPE yy_action[SQLParser_YY_ACTTAB_COUNT];
		static const SQLParser_YYCODETYPE yy_lookahead[SQLParser_YY_ACTTAB_COUNT];
		static const short yy_shift_ofst[SQLParser_YY_SHIFT_COUNT + 1];
		static const short yy_reduce_ofst[SQLParser_YY_REDUCE_COUNT + 1];
		static const SQLParser_YYACTIONTYPE yy_default[];




		/* The next table maps tokens into fallback tokens.  If a construct
		 ** like the following:
		 **
		 **      %fallback ID X Y Z.
		 **
		 ** appears in the grammar, then ID becomes a fallback token for X, Y,
		 ** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
		 ** but it does not parse, the type of the token is changed to ID and
		 ** the parse is retried before an error is thrown.
		 */
#ifdef SQLParser_YYFALLBACK
		static const SQLParser_YYCODETYPE yyFallback[SQLParser_YYNFALLBACK];
#endif /* SQLParser_YYFALLBACK */


		/* The following structure represents a single element of the
		 ** parser's stack.  Information stored includes:
		 **
		 **   +  The state number for the parser at this level of the stack.
		 **
		 **   +  The value of the token stored at this level of the stack.
		 **      (In other words, the "major" token.)
		 **
		 **   +  The semantic value stored at this level of the stack.  This is
		 **      the information used by the action routines in the grammar.
		 **      It is sometimes called the "minor" token.
		 */
		/*!
		 * @brief parser's stack
		 */
		struct yyStackEntry {
			SQLParser_YYACTIONTYPE stateno;  /* The state-number */
			SQLParser_YYCODETYPE major;      /* The major token value.  This is the code
										  ** number for the token at this stack level */
			SQLParser_YYMINORTYPE minor;     /* The user-supplied minor token value.  This
										  ** is the value of the token  */
		};
		typedef struct yyStackEntry yyStackEntry;

		/* The state of the parser is completely contained in an instance of
		 ** the following structure */

		int32_t yyidx;                    /* Index of top element in stack */
#ifdef SQLParser_YYTRACKMAXSTACKDEPTH
		int32_t yyidxMax;                 /* Maximum value of yyidx */
#endif
		int32_t yyerrcnt;                 /* Shifts left before out of the error */
		SQLParserARG_SDECL;               /* A place to hold %extra_argument */
#if SQLParser_YYSTACKDEPTH<=0
		int32_t yystksz;                  /* Current side of the stack */
		yyStackEntry *yystack;        /* The parser's stack */
#else
		yyStackEntry yystack[SQLParser_YYSTACKDEPTH];  /* The parser's stack */
#endif

#ifndef NDEBUG
		std::ostream *yyTraceFILE;
		const char* yyTracePrompt;
#endif /* NDEBUG */

#ifndef NDEBUG
		/*
		 ** Turn parser tracing on by giving a stream to which to write the trace
		 ** and a prompt to preface each trace message.  Tracing is turned off
		 ** by making either argument NULL
		 **
		 ** Inputs:
		 ** <ul>
		 ** <li> A FILE* to which trace output should be written.
		 **      If NULL, then tracing is turned off.
		 ** <li> A prefix string written at the beginning of every
		 **      line of trace output.  If NULL, then tracing is
		 **      turned off.
		 ** </ul>
		 **
		 ** Outputs:
		 ** None.
		 */
	public: void SQLParserSetTrace(std::ostream *TraceFILE, const char *zTracePrompt){
		yyTraceFILE = TraceFILE;
		yyTracePrompt = zTracePrompt;
		if( yyTraceFILE==0 ) yyTraceFILE = 0;
	}
#endif /* NDEBUG */


#ifndef NDEBUG
	protected:
		static const char *const yyTokenName[];
		static const char *const yyRuleName[SQLParser_YYNRULE];
#endif

#if SQLParser_YYSTACKDEPTH<=0
		/*
		 ** Try to increase the size of the parser stack.
		 */
		void yyGrowStack(){
			int32_t newSize;
			yyStackEntry *pNew;

			newSize = yystksz*2 + 100;
			pNew = new yyStackEntry[newSize];
			if( pNew ){
				memcpy(pNew, yystack, newSize*sizeof(pNew[0]));
				delete yystack;
				yystack = pNew;
				yystksz = newSize;
#ifndef NDEBUG
				if( yyTraceFILE ){
					*yyTraceFILE << yyTracePrompt << "Stack grows to " <<
					  yystksz <<" entries!" << std::endl;
				}
#endif
			}
		}
#endif

		/*
		 ** This function allocates a new parser.
		 ** The only argument is a pointer to a function which works like
		 ** malloc.
		 **
		 ** Inputs:
		 ** A pointer to the function used to allocate memory.
		 **
		 ** Outputs:
		 ** A pointer to a parser.  This pointer is used in subsequent calls
		 ** to SQLParser and SQLParserFree.
		 */
	public: SQLParser(){
		yyidx = -1;
#ifdef SQLParser_YYTRACKMAXSTACKDEPTH
		yidxMax = 0;
#endif
#if SQLParser_YYSTACKDEPTH<=0
		yystack = NULL;
		yystksz = 0;
		yyGrowStack();
#else
		memset(yystack, 0, sizeof(yystack));
#endif
#ifndef NDEBUG
		yyTraceFILE = NULL;
#endif
		yyerrcnt = -1;
	}

		/* The following function deletes the value associated with a
		 ** symbol.  The symbol can be either a terminal or nonterminal.
		 ** "yymajor" is the symbol code, and "yypminor" is a pointer to
		 ** the value.
		 */
		void yy_destructor(
			SQLParser_YYCODETYPE yymajor,     /* Type code for object to destroy */
			SQLParser_YYMINORTYPE *yypminor   /* The object to be destroyed */
			){
			switch( yymajor ){
				/* Here is inserted the actions which take place when a
				 ** terminal or non-terminal is destroyed.  This can happen
				 ** when the symbol is popped from the stack during a
				 ** reduce or during error processing or when a parser is
				 ** being destroyed before it is finished parsing.
				 **
				 ** Note: during a reduce, the only symbols destroyed are those
				 ** which appear on the RHS of the rule, but which are not used
				 ** inside the C code.
				 */
    case 188: /* columnlist */
    case 220: /* addcolumnlist */
{
SQLPARSER_SAFE_DELETE((yypminor->yy18));
}
      break;
    case 189: /* conslist_opt */
    case 191: /* createtable_opt */
    case 200: /* createtable_optlist */
    case 206: /* conslist */
    case 208: /* idxlist */
    case 217: /* exprlist */
    case 218: /* idxlist_opt */
    case 222: /* hint_opt */
    case 227: /* selcollist */
    case 232: /* orderby_opt */
    case 235: /* nexprlist */
    case 236: /* hintlist */
    case 237: /* hintlist1 */
    case 239: /* hintexprlist */
    case 240: /* hintexprlist1 */
    case 243: /* sclp */
    case 249: /* using_opt */
    case 250: /* idlist */
    case 251: /* sortlist */
    case 252: /* setlist */
    case 254: /* inscollist_opt */
    case 256: /* partitionby_opt */
    case 261: /* case_exprlist */
{
SQLPARSER_SAFE_DELETE((yypminor->yy294));
}
      break;
    case 192: /* partitioning_options */
{
SQLPARSER_SAFE_DELETE((yypminor->yy437));
}
      break;
    case 193: /* column */
    case 221: /* addcolumn */
{
SQLPARSER_SAFE_DELETE((yypminor->yy12));
}
      break;
    case 195: /* carglist */
{
SQLPARSER_SAFE_DELETE((yypminor->yy232));
}
      break;
    case 196: /* expr */
    case 207: /* tcons */
    case 228: /* from */
    case 229: /* where_opt */
    case 231: /* having_opt */
    case 238: /* onehint */
    case 241: /* hintexpr */
    case 242: /* term */
    case 245: /* seltabtree */
    case 246: /* stl_prefix */
    case 248: /* on_opt */
    case 260: /* case_operand */
    case 262: /* case_else */
{
SQLPARSER_SAFE_DELETE((yypminor->yy60));
}
      break;
    case 212: /* fullname */
{
SQLPARSER_SAFE_DELETE((yypminor->yy295));
}
      break;
    case 215: /* select */
    case 223: /* selectnowith */
    case 234: /* valuelist */
{
SQLPARSER_SAFE_DELETE((yypminor->yy158));
}
      break;
    case 224: /* oneselect */
{
SQLPARSER_SAFE_DELETE((yypminor->yy474));
}
      break;
    case 230: /* groupby_opt */
{
SQLPARSER_SAFE_DELETE((yypminor->yy294));SQLPARSER_SAFE_DELETE((yypminor->yy294));
}
      break;
    case 255: /* window_opt */
{
SQLPARSER_SAFE_DELETE((yypminor->yy115));
}
      break;
			default:  break;   /* If no destructor action specified: do nothing */
			}
		}

		/*
		 ** Pop the parser's stack once.
		 **
		 ** If there is a destructor routine associated with the token which
		 ** is popped from the stack, then call it.
		 **
		 ** Return the major token number for the symbol popped.
		 */
		int32_t yy_pop_parser_stack(){
			SQLParser_YYCODETYPE yymajor;
			yyStackEntry *yytos;

			if( yyidx<0 ) return 0;
			yytos = &yystack[yyidx];
#ifndef NDEBUG
			if( yyTraceFILE && yyidx>=0 ){
				*yyTraceFILE << yyTracePrompt << "Popping " << yyTokenName[yytos->major] << std::endl;
			}
#endif
			yymajor = yytos->major;
			yy_destructor(yymajor, &yytos->minor);
			yyidx--;
			return yymajor;
		}

		/*
		 ** Deallocate and destroy a parser.  Destructors are all called for
		 ** all stack elements before shutting the parser down.
		 **
		 ** Inputs:
		 ** <ul>
		 ** <li>  A pointer to the parser.  This should be a pointer
		 **       obtained from SQLParserAlloc.
		 ** <li>  A pointer to a function used to reclaim memory obtained
		 **       from malloc.
		 ** </ul>
		 */
	public: ~SQLParser(){
		while( yyidx>=0 ) yy_pop_parser_stack();
#if SQLParser_YYSTACKDEPTH<=0
		delete yystack;
		yystack = NULL;
#endif
	}

		/*
		 ** Return the peak depth of the stack for a parser.
		 */
#ifdef SQLParser_YYTRACKMAXSTACKDEPTH
	public: int32_t SQLParserStackPeak(void *p){
		return yyidxMax;
	}
#endif

		/*
		 ** Find the appropriate action for a parser given the terminal
		 ** look-ahead token iLookAhead.
		 **
		 ** If the look-ahead token is SQLParser_YYNOCODE, then check to see if the action is
		 ** independent of the look-ahead.  If it is, return the action, otherwise
		 ** return SQLParser_YY_NO_ACTION.
		 */
		int32_t yy_find_shift_action(
			SQLParser_YYCODETYPE iLookAhead     /* The look-ahead token */
			){
			int32_t i;
			int32_t stateno = this->yystack[this->yyidx].stateno;

			if( stateno>SQLParser_YY_SHIFT_COUNT
				|| (i = yy_shift_ofst[stateno])==SQLParser_YY_SHIFT_USE_DFLT ){
				return yy_default[stateno];
			}
			assert( iLookAhead!=SQLParser_YYNOCODE );
			i += iLookAhead;
			if( i<0 || i>=SQLParser_YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
				if( iLookAhead>0 ){
#ifdef SQLParser_YYFALLBACK
					SQLParser_YYCODETYPE iFallback;            /* Fallback token */
					if( iLookAhead<SQLParser_YYNFALLBACK
						&& (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
						if( yyTraceFILE ){
							*yyTraceFILE << yyTracePrompt << "FALLBACK " << yyTokenName[iLookAhead]
							  << " => " << yyTokenName[iFallback] << std::endl;
						}
#endif
						return yy_find_shift_action(iFallback);
					}
#endif
#ifdef SQLParser_YYWILDCARD
					{
						int32_t j = i - iLookAhead + SQLParser_YYWILDCARD;
						if(
#if SQLParser_YY_SHIFT_MIN+SQLParser_YYWILDCARD<0
							j>=0 &&
#endif
#if SQLParser_YY_SHIFT_MAX+SQLParser_YYWILDCARD>=SQLParser_YY_ACTTAB_COUNT
							j<SQLParser_YY_ACTTAB_COUNT &&
#endif
							yy_lookahead[j]==SQLParser_YYWILDCARD
							){
#ifndef NDEBUG
							if( yyTraceFILE ){
								*yyTraceFILE << yyTracePrompt << "WILDCARD "
								  << yyTokenName[iLookAhead]
									<< " => " << yyTokenName[SQLParser_YYWILDCARD]
									  << std::endl;
							}
#endif /* NDEBUG */
							return yy_action[j];
						}
					}
#endif /* SQLParser_YYWILDCARD */
				}
				return yy_default[stateno];
			}else{
				return yy_action[i];
			}
		}

		/*
		 ** Find the appropriate action for a parser given the non-terminal
		 ** look-ahead token iLookAhead.
		 **
		 ** If the look-ahead token is SQLParser_YYNOCODE, then check to see if the action is
		 ** independent of the look-ahead.  If it is, return the action, otherwise
		 ** return SQLParser_YY_NO_ACTION.
		 */
		int32_t yy_find_reduce_action(
			int32_t stateno,              /* Current state number */
			SQLParser_YYCODETYPE iLookAhead     /* The look-ahead token */
			){
			int32_t i;
#ifdef SQLParser_YYERRORSYMBOL
			if( stateno>SQLParser_YY_REDUCE_COUNT ){
				return yy_default[stateno];
			}
#else
			assert( stateno<=SQLParser_YY_REDUCE_COUNT );
#endif
			i = yy_reduce_ofst[stateno];
			assert( i!=SQLParser_YY_REDUCE_USE_DFLT );
			assert( iLookAhead!=SQLParser_YYNOCODE );
			i += iLookAhead;
#ifdef SQLParser_YYERRORSYMBOL
			if( i<0 || i>=SQLParser_YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
				return yy_default[stateno];
			}
#else
			assert( i>=0 && i<SQLParser_YY_ACTTAB_COUNT );
			assert( yy_lookahead[i]==iLookAhead );
#endif
			return yy_action[i];
		}

		/*
		 ** The following routine is called if the stack overflows.
		 */
		void yyStackOverflow(SQLParser_YYMINORTYPE *yypMinor){
			yyidx--;
#ifndef NDEBUG
			if( yyTraceFILE ){
				*yyTraceFILE << yyTracePrompt << "Stack Overflow!" << std::endl;
			}
#endif
			while( yyidx>=0 ) yy_pop_parser_stack();
			/* Here code is inserted which will execute if the parser
			 ** stack every overflows */

	parser->setError("parser stack overflow");
		}

		/*
		 ** Perform a shift action.
		 */
		void yy_shift(
			int32_t yyNewState,               /* The new state to shift in */
			int32_t yyMajor,                  /* The major token to shift in */
			SQLParser_YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
			){
			yyStackEntry *yytos;
			yyidx++;
#ifdef SQLParser_YYTRACKMAXSTACKDEPTH
			if( yyidx>yyidxMax ){
				yyidxMax = yyidx;
			}
#endif
#if SQLParser_YYSTACKDEPTH>0
			if( yyidx>=SQLParser_YYSTACKDEPTH ){
				yyStackOverflow(yypMinor);
				return;
			}
#else
			if( yyidx>=yystksz ){
				yyGrowStack();
				if( yyidx>=yystksz ){
					yyStackOverflow(yypMinor);
					return;
				}
			}
#endif
			yytos = &yystack[yyidx];
			yytos->stateno = (SQLParser_YYACTIONTYPE)yyNewState;
			yytos->major = (SQLParser_YYCODETYPE)yyMajor;
			yytos->minor = *yypMinor;
#ifndef NDEBUG
			if( yyTraceFILE && yyidx>0 ){
				int32_t i;
				*yyTraceFILE << yyTracePrompt << "Shift " << yyNewState << std::endl;
				*yyTraceFILE << yyTracePrompt << "Stack:";
				for(i=1; i<=yyidx; i++){
					*yyTraceFILE << " " << yyTokenName[yystack[i].major];
				}
				*yyTraceFILE << std::endl;
			}
#endif
		}

		/* The following table contains information about every rule that
		 ** is used during the reduce.
		 */
		/*!
      @brief Contains information about every rule
      that is used during the reduce
		 */
		static const struct RULEINFO{
			SQLParser_YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
			unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
		}yyRuleInfo[];

		/*
		 ** Perform a reduce action and the shift that must immediately
		 ** follow the reduce.
		 */
	private:
		void yy_reduce( int32_t yyruleno                 /* Number of the rule by which to reduce */
						){
			int32_t yygoto;                     /* The next state */
			int32_t yyact;                      /* The next action */
			SQLParser_YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
			yyStackEntry *yymsp;            /* The top of the parser's stack */
			int32_t yysize;                     /* Amount to pop the stack */
			yymsp = &yystack[yyidx];
#ifndef NDEBUG
			if( yyTraceFILE && yyruleno>=0
				&& yyruleno< SQLParser_YYNRULE ){
				*yyTraceFILE << yyTracePrompt << "Reduce ["
				  << yyRuleName[yyruleno] << "]." << std::endl;
			}
#endif /* NDEBUG */

			/* Silence complaints from purify about yygotominor being uninitialized
			 ** in some cases when it is copied into the stack after the following
			 ** switch.  yygotominor is uninitialized when a rule reduces that does
			 ** not set the value of its left-hand side nonterminal.  Leaving the
			 ** value of the nonterminal uninitialized is utterly harmless as long
			 ** as the value is never used.  So really the only thing this code
			 ** accomplishes is to quieten purify.
			 **
			 ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
			 ** without this code, their parser segfaults.  I'm not sure what there
			 ** parser is doing to make this happen.  This is the second bug report
			 ** from wireshark this week.  Clearly they are stressing Lemon in ways
			 ** that it has not been previously stressed...  (SQLite ticket #2172)
			 */
			/*memset(&yygotominor, 0, sizeof(yygotominor));*/
			yygotominor = SQLParser_yyzerominor;


			switch( yyruleno ){
				/* Beginning here are the reduction cases.  A typical example
				 ** follows:
				 **   case 0:
				 **  #line <lineno> <grammarfile>
				 **     { ... }           
				 **  #line <lineno> <thisfile>
				 **     break;
				 */
      case 5: /* explain ::= */
{ parser->beginParse(SyntaxTree::EXPLAIN_NONE); }
        break;
      case 6: /* explain ::= EXPLAIN */
{ parser->beginParse(SyntaxTree::EXPLAIN_PLAN); }
        break;
      case 7: /* explain ::= EXPLAIN ANALYZE */
{ parser->beginParse(SyntaxTree::EXPLAIN_ANALYZE); }
        break;
      case 8: /* cmdx ::= cmd */
{ parser->finishParse(); }
        break;
      case 9: /* cmd ::= BEGIN trans_opt */
{ parser->beginTransaction(0); }
        break;
      case 12: /* cmd ::= COMMIT trans_opt */
      case 13: /* cmd ::= END trans_opt */ yytestcase(yyruleno==13);
{ parser->commitTransaction(); }
        break;
      case 14: /* cmd ::= ROLLBACK trans_opt */
{ parser->rollbackTransaction(); }
        break;
      case 16: /* create_table ::= createkw TABLE ifnotexists nm dbnm LP columnlist conslist_opt RP is_timeseries createtable_opt partitioning_options */
{
	assert(!parser->topSelect_);
	SyntaxTree::Select *select = Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_CREATE_TABLE);

	SyntaxTree::QualifiedName* qName = NULL;
	SQLToken tokenName = yymsp[-8].minor.yy0;
	if (yymsp[-7].minor.yy0.size_ > 0) {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-8].minor.yy0, &yymsp[-7].minor.yy0, NULL);
		tokenName = yymsp[-7].minor.yy0;
	}
	else {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-8].minor.yy0, NULL);
	}
	if (!qName->table_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, tokenName,
				"Table name must not be empty");
	}
	select->targetName_ = qName;

	select->cmdOptionValue_ = yymsp[-9].minor.yy428;

	if (yymsp[-4].minor.yy294) {
		SyntaxTree::checkTableConstraint(parser->getSQLAllocator(), yymsp[-5].minor.yy18, yymsp[-4].minor.yy294);
	}
	select->createTableOpt_ =
		SyntaxTree::makeCreateTableOption(
				parser->getSQLAllocator(), yymsp[-5].minor.yy18, yymsp[-4].minor.yy294, yymsp[0].minor.yy437, yymsp[-1].minor.yy294, yymsp[-9].minor.yy428, NULL, false, yymsp[-2].minor.yy371);

	parser->setTopSelect(select);
}
        break;
      case 18: /* ifnotexists ::= */
      case 67: /* ifexists ::= */ yytestcase(yyruleno==67);
      case 70: /* force ::= */ yytestcase(yyruleno==70);
      case 256: /* between_op ::= BETWEEN */ yytestcase(yyruleno==256);
      case 259: /* in_op ::= IN */ yytestcase(yyruleno==259);
{yygotominor.yy428 = 0;}
        break;
      case 19: /* ifnotexists ::= IF NOT EXISTS */
      case 66: /* ifexists ::= IF EXISTS */ yytestcase(yyruleno==66);
      case 71: /* force ::= FORCE */ yytestcase(yyruleno==71);
      case 257: /* between_op ::= NOT BETWEEN */ yytestcase(yyruleno==257);
      case 260: /* in_op ::= NOT IN */ yytestcase(yyruleno==260);
{yygotominor.yy428 = 1;}
        break;
      case 20: /* columnlist ::= column */
      case 97: /* addcolumnlist ::= addcolumn */ yytestcase(yyruleno==97);
{
	yygotominor.yy18 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::TableColumnList(parser->getSQLAllocator());
	yygotominor.yy18->push_back(yymsp[0].minor.yy12);
}
        break;
      case 21: /* columnlist ::= columnlist COMMA column */
      case 98: /* addcolumnlist ::= addcolumnlist COMMA addcolumn */ yytestcase(yyruleno==98);
{
	yygotominor.yy18 = yymsp[-2].minor.yy18;
	if (!yygotominor.yy18) {
		yygotominor.yy18 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::TableColumnList(parser->getSQLAllocator());
	}
	yygotominor.yy18->push_back(yymsp[0].minor.yy12);
}
        break;
      case 22: /* column ::= nm typetoken carglist */
      case 99: /* addcolumn ::= ADD nm typetoken carglist */ yytestcase(yyruleno==99);
      case 100: /* addcolumn ::= ADD COLUMNKW nm typetoken carglist */ yytestcase(yyruleno==100);
{
	yygotominor.yy12 = SyntaxTree::makeCreateTableColumn(parser->getSQLAllocator(), &yymsp[-2].minor.yy0, &yymsp[-1].minor.yy0, yymsp[0].minor.yy232);
}
        break;
      case 23: /* carglist ::= */
{yygotominor.yy232 = 0;}
        break;
      case 24: /* carglist ::= carglist PRIMARY KEY */
{
	if (!yymsp[-2].minor.yy232) {
		yymsp[-2].minor.yy232 = ALLOC_NEW(parser->getSQLAllocator()) SyntaxTree::ColumnInfo;
	}
	int32_t flag = SyntaxTree::COLUMN_OPT_PRIMARY_KEY;
	if ((yymsp[-2].minor.yy232->option_ & flag) == flag) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"PRIMARY KEY option duplicated");
	}
	if ((yymsp[-2].minor.yy232->option_ & SyntaxTree::COLUMN_OPT_VIRTUAL) != 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"PRIMARY KEY and VIRTUAL options can not be specified at the same time");
	}
	if ((yymsp[-2].minor.yy232->option_ & SyntaxTree::COLUMN_OPT_NULLABLE) != 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"PRIMARY KEY and NULL options can not be specified at the same time");
	}
	yymsp[-2].minor.yy232->option_ |= flag;
	yygotominor.yy232 = yymsp[-2].minor.yy232;
}
        break;
      case 25: /* carglist ::= carglist NOT NULL */
{
	if (!yymsp[-2].minor.yy232) {
		yymsp[-2].minor.yy232 = ALLOC_NEW(parser->getSQLAllocator()) SyntaxTree::ColumnInfo;
	}
	const int32_t flag = SyntaxTree::COLUMN_OPT_NOT_NULL;
	if ((yymsp[-2].minor.yy232->option_ & flag) == flag) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"NOT NULL option duplicated");
	}
	if ((yymsp[-2].minor.yy232->option_ & SyntaxTree::COLUMN_OPT_NULLABLE) != 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"NOT NULL and NULL options can not be specified at the same time");
	}
	yymsp[-2].minor.yy232->option_ |= flag;
	yygotominor.yy232 = yymsp[-2].minor.yy232;
}
        break;
      case 26: /* carglist ::= carglist NULL */
{
	if (!yymsp[-1].minor.yy232) {
		yymsp[-1].minor.yy232 = ALLOC_NEW(parser->getSQLAllocator()) SyntaxTree::ColumnInfo;
	}
	const int32_t flag = SyntaxTree::COLUMN_OPT_NULLABLE;
	if ((yymsp[-1].minor.yy232->option_ & flag) == flag) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"NULL option duplicated");
	}
	if ((yymsp[-1].minor.yy232->option_ & SyntaxTree::COLUMN_OPT_PRIMARY_KEY) != 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"PRIMARY KEY and NULL options can not be specified at the same time");
	}
	if ((yymsp[-1].minor.yy232->option_ & SyntaxTree::COLUMN_OPT_NOT_NULL) != 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"NOT NULL and NULL options can not be specified at the same time");
	}
	yymsp[-1].minor.yy232->option_ |= flag;
	yygotominor.yy232 = yymsp[-1].minor.yy232;
}
        break;
      case 27: /* carglist ::= carglist AS LP expr RP VIRTUAL */
{
	SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-4].minor.yy0,
			"Syntax error");
	yygotominor.yy232 = yymsp[-5].minor.yy232;
  yy_destructor(196,&yymsp[-2].minor);
}
        break;
      case 28: /* partitioning_options ::= */
{yygotominor.yy437 = 0;}
        break;
      case 29: /* partitioning_options ::= PARTITION BY HASH singlecol PARTITIONS INTEGER */
{
	yygotominor.yy437 = ALLOC_NEW(parser->getSQLAllocator()) SyntaxTree::PartitioningOption;
	yygotominor.yy437->partitionType_ = SyntaxTree::TABLE_PARTITION_TYPE_HASH;
	yygotominor.yy437->partitionColumn_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);
	/* yymsp[0].minor.yy0: Token */
	int64_t int64Value;
	bool succeeded = SQLProcessor::ValueUtils::toLong(
			yymsp[0].minor.yy0.value_, yymsp[0].minor.yy0.size_, int64Value);
	if (!succeeded || int64Value <= 0 || int64Value > INT32_MAX) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Table partitioning count must be a positive integer");
	}
	yygotominor.yy437->partitionCount_ = static_cast<int32_t>(int64Value);
	yygotominor.yy437->optInterval_ = 0;
}
        break;
      case 30: /* partitioning_options ::= PARTITION BY RANGE|INTERVAL singlecol intervalOption */
{
	yygotominor.yy437 = ALLOC_NEW(parser->getSQLAllocator()) SyntaxTree::PartitioningOption;
	yygotominor.yy437->partitionType_ = SyntaxTree::TABLE_PARTITION_TYPE_RANGE;
	yygotominor.yy437->partitionColumn_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-1].minor.yy0);
	yygotominor.yy437->optInterval_ = yymsp[0].minor.yy482.value_;
	yygotominor.yy437->optIntervalUnit_ = yymsp[0].minor.yy482.unit_;
}
        break;
      case 31: /* partitioning_options ::= PARTITION BY RANGE|INTERVAL singlecol intervalOption SUBPARTITION BY HASH singlecol SUBPARTITIONS INTEGER */
{

	yygotominor.yy437 = ALLOC_NEW(parser->getSQLAllocator()) SyntaxTree::PartitioningOption;
	yygotominor.yy437->partitionType_ = SyntaxTree::TABLE_PARTITION_TYPE_RANGE_HASH;
	yygotominor.yy437->partitionColumn_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-7].minor.yy0);
	yygotominor.yy437->subPartitionColumn_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);
	/* yymsp[0].minor.yy0: Token */
	int64_t int64Value;
	bool succeeded = SQLProcessor::ValueUtils::toLong(
			yymsp[0].minor.yy0.value_, yymsp[0].minor.yy0.size_, int64Value);
	if (!succeeded || int64Value <= 0 || int64Value > INT32_MAX) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Table partitioning count must be a positive integer");
	}
	yygotominor.yy437->partitionCount_ = static_cast<int32_t>(int64Value);
	yygotominor.yy437->optInterval_ = yymsp[-6].minor.yy482.value_;
	yygotominor.yy437->optIntervalUnit_ = yymsp[-6].minor.yy482.unit_;
}
        break;
      case 32: /* intervalOption ::= EVERY LP INTEGER RP */
{
	/* yymsp[-1].minor.yy0: Token */
	int64_t int64Value;
	bool succeeded = SQLProcessor::ValueUtils::toLong(
			yymsp[-1].minor.yy0.value_, yymsp[-1].minor.yy0.size_, int64Value);
	if (!succeeded || int64Value <= 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"Table partitioning interval must be a positive integer");
	}
	yygotominor.yy482.value_ = int64Value;
	yygotominor.yy482.unit_ = -1;
}
        break;
      case 33: /* intervalOption ::= EVERY LP INTEGER COMMA field RP */
{
	assert(yymsp[-1].minor.yy60); 
	assert(yymsp[-1].minor.yy60->value_.getType() == TupleList::TYPE_LONG);
	int64_t fieldType = yymsp[-1].minor.yy60->value_.get<int64_t>();
	switch(fieldType) {
	case util::DateTime::FIELD_DAY_OF_MONTH:
		break;
	default:
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy60->startToken_,
				"Specified unit is not allowed");
		break;
	}
	/* yymsp[-3].minor.yy0: Token */
	int64_t int64Value;
	bool succeeded = SQLProcessor::ValueUtils::toLong(
			yymsp[-3].minor.yy0.value_, yymsp[-3].minor.yy0.size_, int64Value);
	if (!succeeded || int64Value <= 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-3].minor.yy0,
				"Table partitioning interval must be a positive integer");
	}
	yygotominor.yy482.value_ = int64Value;
	yygotominor.yy482.unit_ = fieldType;
}
        break;
      case 34: /* is_timeseries ::= */
      case 90: /* sortascending ::= DESC */ yytestcase(yyruleno==90);
{yygotominor.yy371 = false;}
        break;
      case 35: /* is_timeseries ::= USING TIMESERIES */
      case 89: /* sortascending ::= ASC */ yytestcase(yyruleno==89);
      case 91: /* sortascending ::= */ yytestcase(yyruleno==91);
{yygotominor.yy371 = true;}
        break;
      case 36: /* singlecol ::= nm */
      case 44: /* plus_num ::= PLUS INTEGER|FLOAT */ yytestcase(yyruleno==44);
      case 45: /* plus_num ::= INTEGER|FLOAT */ yytestcase(yyruleno==45);
      case 46: /* minus_num ::= MINUS INTEGER|FLOAT */ yytestcase(yyruleno==46);
      case 47: /* nm ::= ID */ yytestcase(yyruleno==47);
      case 48: /* typetoken ::= typename */ yytestcase(yyruleno==48);
      case 53: /* typename ::= ID */ yytestcase(yyruleno==53);
      case 141: /* as ::= AS nm */ yytestcase(yyruleno==141);
      case 142: /* as ::= ID */ yytestcase(yyruleno==142);
      case 153: /* dbnm ::= DOT nm */ yytestcase(yyruleno==153);
{yygotominor.yy0 = yymsp[0].minor.yy0;}
        break;
      case 37: /* singlecol ::= LP nm RP */
{yygotominor.yy0 = yymsp[-1].minor.yy0;}
        break;
      case 38: /* createtable_opt ::= */
      case 57: /* conslist_opt ::= */ yytestcase(yyruleno==57);
      case 116: /* hint_opt ::= */ yytestcase(yyruleno==116);
      case 118: /* hintlist ::= */ yytestcase(yyruleno==118);
      case 123: /* hintexprlist ::= */ yytestcase(yyruleno==123);
      case 174: /* using_opt ::= */ yytestcase(yyruleno==174);
      case 175: /* orderby_opt ::= */ yytestcase(yyruleno==175);
      case 179: /* groupby_opt ::= */ yytestcase(yyruleno==179);
      case 196: /* inscollist_opt ::= */ yytestcase(yyruleno==196);
      case 223: /* partitionby_opt ::= */ yytestcase(yyruleno==223);
      case 273: /* exprlist ::= */ yytestcase(yyruleno==273);
{yygotominor.yy294 = 0;}
        break;
      case 39: /* createtable_opt ::= WITH LP createtable_optlist RP */
{
	yygotominor.yy294 = yymsp[-1].minor.yy294;
}
        break;
      case 40: /* createtable_optlist ::= createtable_optlist COMMA nm EQ expr */
{
	assert(yymsp[0].minor.yy60);
	if (yymsp[0].minor.yy60->op_ != SQLType::EXPR_CONSTANT) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy60->startToken_,
				"Option value must be constant");
	}
	if (!yymsp[-4].minor.yy294) {
		yymsp[-4].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	util::String *keyStr = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[-2].minor.yy0, false);
	yymsp[0].minor.yy60->aliasName_ = keyStr;

	yygotominor.yy294 = yymsp[-4].minor.yy294;
	yygotominor.yy294->push_back(yymsp[0].minor.yy60);
}
        break;
      case 41: /* createtable_optlist ::= nm EQ expr */
{
	assert(yymsp[0].minor.yy60);
	if (yymsp[0].minor.yy60->op_ != SQLType::EXPR_CONSTANT) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy60->startToken_,
				"Option value must be constant");
	}
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	util::String *keyStr = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[-2].minor.yy0, false);
	yymsp[0].minor.yy60->aliasName_ = keyStr;

	yygotominor.yy294->push_back(yymsp[0].minor.yy60);
}
        break;
      case 43: /* create_virtual_table ::= createkw VIRTUAL TABLE ifnotexists nm dbnm LP columnlist conslist_opt RP USING nm createtable_opt partitioning_options */
{
	SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-12].minor.yy0,
			"Syntax error");
  yy_destructor(188,&yymsp[-6].minor);
  yy_destructor(189,&yymsp[-5].minor);
  yy_destructor(192,&yymsp[0].minor);
}
        break;
      case 49: /* typetoken ::= typename LP signed RP */
{
	yygotominor.yy0 = yymsp[-3].minor.yy0;
}
        break;
      case 50: /* typetoken ::= typename LP signed RP typename */
{
	yygotominor.yy0 = yymsp[-4].minor.yy0;
}
        break;
      case 51: /* typetoken ::= typename LP signed COMMA signed RP */
{
	yygotominor.yy0 = yymsp[-5].minor.yy0;
}
        break;
      case 52: /* typetoken ::= typename LP signed COMMA signed RP typename */
{
	yygotominor.yy0 = yymsp[-6].minor.yy0;
}
        break;
      case 54: /* typename ::= typename ID */
{
	yygotominor.yy0 = yymsp[-1].minor.yy0;
}
        break;
      case 58: /* conslist_opt ::= COMMA conslist */
      case 117: /* hintlist ::= hintlist1 */ yytestcase(yyruleno==117);
      case 122: /* hintexprlist ::= hintexprlist1 */ yytestcase(yyruleno==122);
      case 176: /* orderby_opt ::= ORDER BY sortlist */ yytestcase(yyruleno==176);
      case 180: /* groupby_opt ::= GROUP BY nexprlist */ yytestcase(yyruleno==180);
      case 224: /* partitionby_opt ::= PARTITION BY nexprlist */ yytestcase(yyruleno==224);
      case 272: /* exprlist ::= nexprlist */ yytestcase(yyruleno==272);
{yygotominor.yy294 = yymsp[0].minor.yy294;}
        break;
      case 59: /* conslist ::= tcons */
{
	if (yymsp[0].minor.yy60) {
		yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
		yygotominor.yy294->push_back(yymsp[0].minor.yy60);
	}
	else {
		yygotominor.yy294 = 0;
	}
}
        break;
      case 60: /* tcons ::= PRIMARY KEY LP idxlist RP */
{
	SyntaxTree::Expr* expr = SyntaxTree::Expr::makeExpr(
		parser->getSQLAllocator(), SQLType::EXPR_COLUMN);
	expr->next_ = yymsp[-1].minor.yy294;
	yygotominor.yy60 = expr;
}
        break;
      case 61: /* orconf ::= */
{yygotominor.yy428 = SyntaxTree::RESOLVETYPE_DEFAULT;}
        break;
      case 62: /* orconf ::= OR resolvetype */
{yygotominor.yy428 = yymsp[0].minor.yy428;}
        break;
      case 63: /* resolvetype ::= IGNORE */
{yygotominor.yy428 = SyntaxTree::RESOLVETYPE_IGNORE;}
        break;
      case 64: /* resolvetype ::= REPLACE */
{yygotominor.yy428 = SyntaxTree::RESOLVETYPE_REPLACE;}
        break;
      case 65: /* cmd ::= DROP TABLE ifexists fullname */
{
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_DROP_TABLE);

	select->targetName_ = yymsp[0].minor.yy295;
	select->cmdOptionValue_ = yymsp[-1].minor.yy428;
	parser->setTopSelect(select);
}
        break;
      case 69: /* create_view ::= CREATE force VIEW nm dbnm AS select */
{
	assert(!parser->topSelect_);
	SyntaxTree::Select *select = Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_CREATE_VIEW);

	SyntaxTree::QualifiedName* qName = NULL;
	SQLToken tokenName = yymsp[-3].minor.yy0;
	if (yymsp[-2].minor.yy0.size_ > 0) {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-3].minor.yy0, &yymsp[-2].minor.yy0, NULL);
		tokenName = yymsp[-2].minor.yy0;
	}
	else {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-3].minor.yy0, NULL);
	}
	if (!qName->table_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, tokenName,
				"View name must not be empty");
	}
	select->targetName_ = qName;

	assert(yymsp[0].minor.yy158);
	if (yymsp[0].minor.yy158 && yymsp[0].minor.yy158->right_ && yymsp[0].minor.yy158->right_->hintList_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				yymsp[-1].minor.yy0, "Hint specified in View definition");
	}
	select->insertSet_ = yymsp[0].minor.yy158;
	SQLAllocator &alloc = parser->getSQLAllocator();

	SQLToken tokenAs = yymsp[-1].minor.yy0;
	size_t tailLen = strlen(tokenAs.value_ + tokenAs.size_);
	util::String* viewSelectStr =
		ALLOC_NEW(alloc) util::String(tokenAs.value_+ tokenAs.size_, tailLen, alloc);


	SyntaxTree::CreateTableOption *opt =
			ALLOC_NEW(alloc) SyntaxTree::CreateTableOption(alloc);
	opt->optionString_ = viewSelectStr;
	select->createTableOpt_ = opt;
	select->cmdOptionValue_ = yymsp[-5].minor.yy428;

	parser->setTopSelect(select);

	if (yymsp[-5].minor.yy428 == 1) {
		parser->createForceView_ = true;
	}

}
        break;
      case 72: /* cmd ::= DROP VIEW ifexists fullname */
{
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_DROP_VIEW);

	select->targetName_ = yymsp[0].minor.yy295;
	select->cmdOptionValue_ = yymsp[-1].minor.yy428;
	parser->setTopSelect(select);
}
        break;
      case 73: /* cmd ::= CREATE DATABASE nm */
{
	/* yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_CREATE_DATABASE);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Database name must not be empty");
	}
	select->cmdOptionList_->push_back(nameExpr);

	parser->setTopSelect(select);
}
        break;
      case 74: /* cmd ::= DROP DATABASE nm */
{
	/* yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_DROP_DATABASE);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Database name must not be empty");
	}
	select->cmdOptionList_->push_back(nameExpr);
	parser->setTopSelect(select);
}
        break;
      case 75: /* cmd ::= CREATE USER nm IDENTIFIED BY STRING */
{
	/* yymsp[-3].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_CREATE_USER);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr1 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr1->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-3].minor.yy0);

	if (!nameExpr1->qName_->name_ || nameExpr1->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-3].minor.yy0,
				"User name must not be empty");
	}

	SyntaxTree::Expr* nameExpr2 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	util::String *nameStr = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[0].minor.yy0, true);
	if (nameStr) {
		nameExpr2->value_ = SyntaxTree::makeStringValue(
				parser->getSQLAllocator(), nameStr->c_str(), nameStr->size());
	}
	select->cmdOptionList_->push_back(nameExpr1);
	select->cmdOptionList_->push_back(nameExpr2);

	parser->setTopSelect(select);
}
        break;
      case 76: /* cmd ::= CREATE USER nm */
{
	/* yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_CREATE_USER);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"User name must not be empty");
	}
	select->cmdOptionList_->push_back(nameExpr);
	select->cmdOptionList_->push_back(NULL);

	parser->setTopSelect(select);
}
        break;
      case 77: /* cmd ::= SET PASSWORD FOR nm EQ STRING */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_SET_PASSWORD);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr1 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr1->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);
	if (!nameExpr1->qName_->name_ || nameExpr1->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"User name must not be empty");
	}

	SyntaxTree::Expr* nameExpr2 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	util::String *nameStr = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[0].minor.yy0, true);
	if (nameStr) {
		nameExpr2->value_ = SyntaxTree::makeStringValue(
				parser->getSQLAllocator(), nameStr->c_str(), nameStr->size());
	}
	select->cmdOptionList_->push_back(nameExpr1);
	select->cmdOptionList_->push_back(nameExpr2);

	parser->setTopSelect(select);
}
        break;
      case 78: /* cmd ::= SET PASSWORD EQ STRING */
{
	/* yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_SET_PASSWORD);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr2 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	util::String *nameStr = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[0].minor.yy0, true);
	if (nameStr) {
		nameExpr2->value_ = SyntaxTree::makeStringValue(
			parser->getSQLAllocator(), nameStr->c_str(), nameStr->size());
	}

	select->cmdOptionList_->push_back(NULL);
	select->cmdOptionList_->push_back(nameExpr2);

	parser->setTopSelect(select);
}
        break;
      case 79: /* cmd ::= DROP USER nm */
{
	/* yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_DROP_USER);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"User name must not be empty");
	}
	select->cmdOptionList_->push_back(nameExpr);

	parser->setTopSelect(select);
}
        break;
      case 80: /* cmd ::= GRANT ALL ON nm TO nm */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_GRANT);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr1 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr1->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);

	if (!nameExpr1->qName_->name_ || nameExpr1->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"User name must not be empty");
	}

	SyntaxTree::Expr* nameExpr2 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr2->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr2->qName_->name_ || nameExpr2->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Object name must not be empty");
	}
	select->cmdOptionList_->push_back(nameExpr1);
	select->cmdOptionList_->push_back(nameExpr2);
	Expr* expr = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	int32_t role = 0;
	expr->value_ = TupleValue(role);
	select->cmdOptionList_->push_back(expr);

	parser->setTopSelect(select);
}
        break;
      case 81: /* cmd ::= GRANT SELECT ON nm TO nm */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_GRANT);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr1 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr1->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);

	if (!nameExpr1->qName_->name_ || nameExpr1->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"User name must not be empty");
	}

	SyntaxTree::Expr* nameExpr2 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr2->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr2->qName_->name_ || nameExpr2->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Object name must not be empty");
	}
	select->cmdOptionList_->push_back(nameExpr1);
	select->cmdOptionList_->push_back(nameExpr2);

	Expr* expr = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	int32_t role = 1;
	expr->value_ = TupleValue(role);
	select->cmdOptionList_->push_back(expr);

	parser->setTopSelect(select);
}
        break;
      case 82: /* cmd ::= REVOKE ALL ON nm FROM nm */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_REVOKE);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr1 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr1->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);

	if (!nameExpr1->qName_->name_ || nameExpr1->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"User name must not be empty");
	}

	SyntaxTree::Expr* nameExpr2 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr2->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr2->qName_->name_ || nameExpr2->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Object name must not be empty");
	}

	select->cmdOptionList_->push_back(nameExpr1);
	select->cmdOptionList_->push_back(nameExpr2);
	Expr* expr = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	int32_t role = 0;
	expr->value_ = TupleValue(role);
	select->cmdOptionList_->push_back(expr);

	parser->setTopSelect(select);
}
        break;
      case 83: /* cmd ::= REVOKE SELECT ON nm FROM nm */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0: Token */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_REVOKE);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr1 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr1->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);

	if (!nameExpr1->qName_->name_ || nameExpr1->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"User name must not be empty");
	}

	SyntaxTree::Expr* nameExpr2 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr2->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr2->qName_->name_ || nameExpr2->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Object name must not be empty");
	}

	select->cmdOptionList_->push_back(nameExpr1);
	select->cmdOptionList_->push_back(nameExpr2);

	Expr* expr = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	int32_t role = 1;
	expr->value_ = TupleValue(role);
	select->cmdOptionList_->push_back(expr);

	parser->setTopSelect(select);
}
        break;
      case 84: /* cmd ::= CREATE INDEX ifnotexists nm ON nm dbnm LP idxlist RP using_options */
{
	/* yymsp[-7].minor.yy0, yymsp[-5].minor.yy0, yymsp[-4].minor.yy0: Token, yymsp[-2].minor.yy294: ExprList */
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_CREATE_INDEX);

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ID);
	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-7].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-7].minor.yy0,
				"Index name must not be empty");
	}
	select->cmdOptionList_->push_back(nameExpr);

	SyntaxTree::QualifiedName* qName = NULL;
	if (yymsp[-4].minor.yy0.size_ > 0) {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-5].minor.yy0, &yymsp[-4].minor.yy0, &yymsp[-7].minor.yy0);
	}
	else {
		if (yymsp[-5].minor.yy0.size_ > 0) {
			qName = SyntaxTree::QualifiedName::makeQualifiedName(
					parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-5].minor.yy0, &yymsp[-7].minor.yy0);
			
			if (!qName->table_ || qName->table_->size() == 0) {
				SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-5].minor.yy0,
						"Table name must not be empty");
			}
		}
		else {
			GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					"Table name must not be empty");
		}
	}
	if (!qName->table_ || qName->table_->size() == 0) {
		GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				"Table name must not be empty");
	}
	select->targetName_ = qName;

	select->insertList_ = yymsp[-2].minor.yy294;
	select->cmdOptionValue_ = yymsp[-8].minor.yy428;

	select->createIndexOpt_ =
		SyntaxTree::makeCreateIndexOption(
			parser->getSQLAllocator(), yymsp[-2].minor.yy294, yymsp[-8].minor.yy428, yymsp[0].minor.yy329);

	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), qName, NULL);
	parser->tableList_.push_back(table);

	parser->setTopSelect(select);
}
        break;
      case 85: /* using_options ::= */
{yygotominor.yy329 = 0;}
        break;
      case 86: /* using_options ::= USING nm LP exprlist RP */
{
	if (yymsp[-1].minor.yy294) {
		SyntaxTree::ExprList::iterator itr = yymsp[-1].minor.yy294->begin();
		for (; itr != yymsp[-1].minor.yy294->end(); ++itr) {
			if (((*itr)->op_ != SQLType::EXPR_CONSTANT)
				&& ((*itr)->op_ != SQLType::EXPR_PLACEHOLDER)) {
				GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					"USING options must be CONSTANT or PLACE_HOLDER");
			}
		}
	}
	yygotominor.yy329 = ALLOC_NEW(parser->getSQLAllocator()) SyntaxTree::CreateIndexOption;
	yygotominor.yy329->extensionName_ = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[-3].minor.yy0, true);
	yygotominor.yy329->extensionOptionList_ = yymsp[-1].minor.yy294;
}
        break;
      case 87: /* idxlist ::= idxlist COMMA nm sortascending */
{
	SyntaxTree::Expr* expr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_COLUMN);
	expr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-1].minor.yy0);
	expr->sortAscending_ = yymsp[0].minor.yy371;
	if (!expr->qName_->name_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"Zero-length delimited identifier");
	}
	if (!yymsp[-3].minor.yy294) {
		yymsp[-3].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	yymsp[-3].minor.yy294->push_back(expr);
	yygotominor.yy294 = yymsp[-3].minor.yy294;
}
        break;
      case 88: /* idxlist ::= nm sortascending */
{
	SyntaxTree::Expr* expr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_COLUMN);
	expr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-1].minor.yy0);
	if (!expr->qName_->name_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"Zero-length delimited identifier");
	}
	expr->sortAscending_ = yymsp[0].minor.yy371;

	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yygotominor.yy294->push_back(expr);
}
        break;
      case 92: /* cmd ::= DROP INDEX ifexists nm ON nm dbnm */
{
	SyntaxTree::QualifiedName* qName = NULL;
	if (yymsp[0].minor.yy0.size_ > 0) {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-1].minor.yy0, &yymsp[0].minor.yy0, &yymsp[-3].minor.yy0);
	}
	else {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-1].minor.yy0, &yymsp[-3].minor.yy0);
	}

	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_DROP_INDEX);

	select->targetName_ = qName;
	select->cmdOptionValue_ = yymsp[-4].minor.yy428;

	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), qName, NULL);
	parser->tableList_.push_back(table);

	parser->setTopSelect(select);
}
        break;
      case 93: /* cmd ::= DROP INDEX ifexists nm DOT nm dbnm */
{
	SyntaxTree::QualifiedName* qName = NULL;
	if (yymsp[0].minor.yy0.size_ > 0) {
		assert(yymsp[-1].minor.yy0.size_ > 0);
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-3].minor.yy0, &yymsp[-1].minor.yy0, &yymsp[0].minor.yy0);
	}
	else {
		assert(yymsp[-1].minor.yy0.size_ > 0);
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-3].minor.yy0, &yymsp[-1].minor.yy0);
	}
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_DROP_INDEX);

	select->targetName_ = qName;
	select->cmdOptionValue_ = yymsp[-4].minor.yy428;

	parser->setTopSelect(select);
}
        break;
      case 94: /* cmd ::= DROP INDEX ifexists nm */
{
	SyntaxTree::QualifiedName* qName = NULL;
	SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
			"Table name is missing");
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_DROP_INDEX);

	select->targetName_ = qName;
	select->cmdOptionValue_ = yymsp[-1].minor.yy428;

	parser->setTopSelect(select);
}
        break;
      case 95: /* cmd ::= ALTER TABLE nm DROP PARTITION FOR LP expr RP */
{
	SyntaxTree::QualifiedName* largeQName = NULL;
	largeQName = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-6].minor.yy0, NULL);

	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_ALTER_TABLE_DROP_PARTITION);

	select->targetName_ = largeQName;

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	if (yymsp[-1].minor.yy60 && yymsp[-1].minor.yy60->op_ == SQLType::EXPR_CONSTANT) {
		SQLToken T = yymsp[-1].minor.yy60->startToken_;
		if ((yymsp[-1].minor.yy60->value_.getType() == TupleList::TYPE_LONG)
				|| (yymsp[-1].minor.yy60->value_.getType() == TupleList::TYPE_STRING)) {
			select->cmdOptionList_->push_back(yymsp[-1].minor.yy60);
		}
		else {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					T, "Invalid value specified");
		}
	}
	else {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				yymsp[-1].minor.yy60->startToken_, "Parameter must be constant");
	}

	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), largeQName, NULL);
	parser->tableList_.push_back(table);

	parser->setTopSelect(select);
}
        break;
      case 96: /* cmd ::= ALTER TABLE nm addcolumnlist */
{
	SyntaxTree::QualifiedName* largeQName = NULL;
	largeQName = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-1].minor.yy0, NULL);

	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_ALTER_TABLE_ADD_COLUMN);

	select->targetName_ = largeQName;

	select->cmdOptionList_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), largeQName, NULL);
	parser->tableList_.push_back(table);

	select->createTableOpt_ =
		SyntaxTree::makeAlterTableAddColumnOption(parser->getSQLAllocator(), yymsp[0].minor.yy18);

	parser->setTopSelect(select);
}
        break;
      case 101: /* cmd ::= PRAGMA nm DOT nm DOT nm EQ nm */
{
	parser->setPragma(yymsp[-6].minor.yy0, yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0, 0);
}
        break;
      case 102: /* cmd ::= PRAGMA nm DOT nm DOT nm EQ plus_num */
{
	parser->setPragma(yymsp[-6].minor.yy0, yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0, 1);
}
        break;
      case 103: /* cmd ::= PRAGMA nm DOT nm DOT nm EQ minus_num */
{
	parser->setPragma(yymsp[-6].minor.yy0, yymsp[-4].minor.yy0, yymsp[-2].minor.yy0, yymsp[0].minor.yy0, 2);
}
        break;
      case 104: /* cmd ::= hint_opt select */
{
	if (yymsp[0].minor.yy158) {
		if (!yymsp[0].minor.yy158->left_ && yymsp[0].minor.yy158->right_ && !yymsp[0].minor.yy158->unionAllList_) {
			if (yymsp[-1].minor.yy294) {
				yymsp[0].minor.yy158->right_->hintList_ = yymsp[-1].minor.yy294;
				const SyntaxTree::Select* hintSelect = parser->getHintSelect();
				if (hintSelect != NULL && hintSelect != yymsp[0].minor.yy158->right_) {
					SQLToken token;
					if (yymsp[-1].minor.yy294->size() > 0) {
						token = yymsp[-1].minor.yy294->at(0)->startToken_;
					}
					else if (hintSelect->hintList_ &&
							 hintSelect->hintList_->size() > 0) {
						token = hintSelect->hintList_->at(0)->startToken_;
					}
					SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
							token, "Hint specified more than once");
				}
				else {
					parser->setHintSelect(yymsp[0].minor.yy158->right_);
				}
			}
			parser->setTopSelect(yymsp[0].minor.yy158->right_);
		}
		else {
			SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
					parser->getSQLAllocator(), SyntaxTree::CMD_SELECT);

			SyntaxTree::Expr* star = SyntaxTree::Expr::makeExpr(
					parser->getSQLAllocator(), SQLType::EXPR_ALL_COLUMN);

			select->selectList_ = ALLOC_NEW(parser->getSQLAllocator())
					SyntaxTree::ExprList(parser->getSQLAllocator());
			select->selectList_->push_back(star);

			SyntaxTree::Expr* selectExpr = SyntaxTree::Expr::makeExpr(
					parser->getSQLAllocator(), SQLType::EXPR_SELECTION);
					selectExpr->subQuery_ = yymsp[0].minor.yy158;

			if (yymsp[-1].minor.yy294) {
				select->hintList_ = yymsp[-1].minor.yy294;
			}
			else {
				SyntaxTree::Set* leftMostSet = yymsp[0].minor.yy158;
				while(leftMostSet->left_) {
					leftMostSet = leftMostSet->left_;
				}
				assert(leftMostSet);
				if (leftMostSet->right_) {
					if (leftMostSet->right_->hintList_) {
						select->hintList_ = leftMostSet->right_->hintList_;
						leftMostSet->right_->hintList_ = NULL;
					}
				}
				else if (leftMostSet->unionAllList_ 
						&& leftMostSet->unionAllList_->at(0)
						&& leftMostSet->unionAllList_->at(0)->hintList_) {
					select->hintList_ = leftMostSet->unionAllList_->at(0)->hintList_;
					leftMostSet->unionAllList_->at(0)->hintList_ = NULL;
				}
			}
			select->from_ = selectExpr;

			parser->setTopSelect(select);

			const SyntaxTree::Select* hintSelect = parser->getHintSelect();
			if (hintSelect != NULL && hintSelect != select &&
					hintSelect->hintList_ != NULL) {
				SQLToken token;
				if (hintSelect->hintList_->size() > 0) {
					token = hintSelect->hintList_->at(0)->startToken_;
				}
				else if (select->hintList_ && select->hintList_->size() > 0) {
					token = select->hintList_->at(0)->startToken_;
				}
				SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
						token, "Invalid hint found");
			}
			if (select->hintList_ != NULL) {
				parser->setHintSelect(select);
			}
		}
	}
	else {
		parser->setTopSelect(NULL);
	}
}
        break;
      case 105: /* select ::= oneselect */
{
	yygotominor.yy158 = SyntaxTree::Set::makeSet(parser->getSQLAllocator(),
		SyntaxTree::SET_OP_NONE, yymsp[0].minor.yy474);
	parser->currentSelect_ = yymsp[0].minor.yy474;
}
        break;
      case 106: /* select ::= select multiselect_op oneselect */
{
	assert(yymsp[-2].minor.yy158);
	if (yymsp[0].minor.yy474) {
		SyntaxTree::Select* lastSelect = NULL;
		if (yymsp[-2].minor.yy158->right_) {
			lastSelect = yymsp[-2].minor.yy158->right_;
		}
		else {
			assert(yymsp[-2].minor.yy158->unionAllList_);
			lastSelect = yymsp[-2].minor.yy158->unionAllList_->back();
		}
		if (lastSelect->orderByList_ || lastSelect->limitList_) {
			util::String unionOpName(parser->getSQLAllocator());
			switch (yymsp[-1].minor.yy69) {
			case SyntaxTree::SET_OP_UNION:
				unionOpName = "UNION";
				break;
			case SyntaxTree::SET_OP_UNION_ALL:
				unionOpName = "UNION ALL";
				break;
			case SyntaxTree::SET_OP_EXCEPT:
				unionOpName = "EXCEPT";
				break;
			case SyntaxTree::SET_OP_INTERSECT:
				unionOpName = "INTERSECT";
				break;
			}
			GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				"ORDER BY or LIMIT clause should come after " 
				<< unionOpName.c_str() << " not before");
		}
		if (yymsp[-1].minor.yy69 == SyntaxTree::SET_OP_UNION_ALL) {
			if (yymsp[-2].minor.yy158->type_ == SyntaxTree::SET_OP_UNION_ALL) {
				assert(yymsp[-2].minor.yy158->unionAllList_);
				yygotominor.yy158 = yymsp[-2].minor.yy158;
				yygotominor.yy158->unionAllList_->push_back(yymsp[0].minor.yy474);
			}
			else if (yymsp[-2].minor.yy158->type_ == SyntaxTree::SET_OP_NONE) {
				assert(!yymsp[-2].minor.yy158->unionAllList_);
				yymsp[-2].minor.yy158->unionAllList_ = ALLOC_NEW(parser->getSQLAllocator())
						SyntaxTree::SelectList(parser->getSQLAllocator());
				if (yymsp[-2].minor.yy158->right_) {
					yymsp[-2].minor.yy158->unionAllList_->push_back(yymsp[-2].minor.yy158->right_);
					yymsp[-2].minor.yy158->right_ = NULL;
				}
				yymsp[-2].minor.yy158->type_ = yymsp[-1].minor.yy69; 
				yygotominor.yy158 = yymsp[-2].minor.yy158;
				yygotominor.yy158->unionAllList_->push_back(yymsp[0].minor.yy474);
			}
			else {
				SyntaxTree::SelectList* unionAllList = ALLOC_NEW(parser->getSQLAllocator())
						SyntaxTree::SelectList(parser->getSQLAllocator());
				unionAllList->push_back(yymsp[0].minor.yy474);

				yygotominor.yy158 = SyntaxTree::Set::makeSet(
						parser->getSQLAllocator(), yymsp[-1].minor.yy69, yymsp[-2].minor.yy158, NULL, unionAllList);
			}
		}
		else {
			yygotominor.yy158 = SyntaxTree::Set::makeSet(parser->getSQLAllocator(), yymsp[-1].minor.yy69, yymsp[-2].minor.yy158, yymsp[0].minor.yy474, NULL);
		}
	}
	else {
		yygotominor.yy158 = yymsp[-2].minor.yy158;
	}
}
        break;
      case 107: /* multiselect_op ::= UNION */
{yygotominor.yy69 = SyntaxTree::SET_OP_UNION;}
        break;
      case 108: /* multiselect_op ::= UNION ALL */
{yygotominor.yy69 = SyntaxTree::SET_OP_UNION_ALL;}
        break;
      case 109: /* multiselect_op ::= EXCEPT */
{yygotominor.yy69 = SyntaxTree::SET_OP_EXCEPT;}
        break;
      case 110: /* multiselect_op ::= INTERSECT */
{yygotominor.yy69 = SyntaxTree::SET_OP_INTERSECT;}
        break;
      case 111: /* oneselect ::= SELECT hint_opt distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt */
{
	/* yymsp[-9].minor.yy0: Token */
	yygotominor.yy474 = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_SELECT,
			yymsp[-6].minor.yy294, yymsp[-7].minor.yy168, yymsp[-5].minor.yy60, yymsp[-4].minor.yy60, yymsp[-3].minor.yy294, yymsp[-2].minor.yy60, yymsp[-1].minor.yy294, yymsp[0].minor.yy294, yymsp[-8].minor.yy294);

	if (yymsp[-8].minor.yy294 != NULL) {
		const SyntaxTree::Select* hintSelect = parser->getHintSelect();
		if (hintSelect != NULL && hintSelect->hintList_ != NULL &&
				hintSelect->hintList_ != yymsp[-8].minor.yy294) {
			SQLToken token;
			if (yymsp[-8].minor.yy294->size() > 0) {
				token = yymsp[-8].minor.yy294->at(0)->startToken_;
			}
			else if (hintSelect->hintList_->size() > 0) {
				token = hintSelect->hintList_->at(0)->startToken_;
			}
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					token, "Hint specified more than once");
		}
		else {
			parser->setHintSelect(yygotominor.yy474);
		}
	}

	parser->currentSelect_ = yygotominor.yy474;
	if (parser->childrenList_.size() > 0) {
		for (size_t pos = 0; pos < parser->childrenList_.size(); ++pos) {
			parser->childrenList_[pos]->parent_ = yygotominor.yy474;
		}
		parser->childrenList_.clear();
	}
	parser->childrenList_.push_back(yygotominor.yy474);
}
        break;
      case 112: /* select ::= valuelist */
{yygotominor.yy158 = yymsp[0].minor.yy158;}
        break;
      case 113: /* valuelist ::= VALUES LP nexprlist RP */
{
	SyntaxTree::Select* select =  SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_SELECT,
			yymsp[-1].minor.yy294, SyntaxTree::AGGR_OPT_ALL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	yygotominor.yy158 = SyntaxTree::Set::makeSet(parser->getSQLAllocator(),
			SyntaxTree::SET_OP_NONE, select);
	parser->currentSelect_ = select;
	if (parser->childrenList_.size() > 0) {
		for (size_t pos = 0; pos < parser->childrenList_.size(); ++pos) {
			parser->childrenList_[pos]->parent_ = select;
		}
		parser->childrenList_.clear();
	}
	parser->childrenList_.push_back(select);
}
        break;
      case 114: /* valuelist ::= valuelist COMMA LP exprlist RP */
{
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_SELECT,
			yymsp[-1].minor.yy294, SyntaxTree::AGGR_OPT_ALL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

	assert(yymsp[-4].minor.yy158);
	if (yymsp[-4].minor.yy158->type_ == SyntaxTree::SET_OP_NONE) {
		assert(!yymsp[-4].minor.yy158->unionAllList_);
		yymsp[-4].minor.yy158->unionAllList_ = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::SelectList(parser->getSQLAllocator());
		if (yymsp[-4].minor.yy158->right_) {
			yymsp[-4].minor.yy158->unionAllList_->push_back(yymsp[-4].minor.yy158->right_);
			yymsp[-4].minor.yy158->right_ = NULL;
		}
		yymsp[-4].minor.yy158->type_ = SyntaxTree::SET_OP_UNION_ALL;
		yygotominor.yy158 = yymsp[-4].minor.yy158;
		yygotominor.yy158->unionAllList_->push_back(select);
	}
	else {
		assert(yymsp[-4].minor.yy158->type_ == SyntaxTree::SET_OP_UNION_ALL);
		yygotominor.yy158 = yymsp[-4].minor.yy158;
		yygotominor.yy158->unionAllList_->push_back(select);
	}
	parser->currentSelect_ = select;
	if (parser->childrenList_.size() > 0) {
		for (size_t pos = 0; pos < parser->childrenList_.size(); ++pos) {
			parser->childrenList_[pos]->parent_ = select;
		}
		parser->childrenList_.clear();
	}
	parser->childrenList_.push_back(select);
}
        break;
      case 115: /* hint_opt ::= HINT_START hintlist HINT_END */
      case 136: /* sclp ::= selcollist COMMA */ yytestcase(yyruleno==136);
{
	yygotominor.yy294 = yymsp[-1].minor.yy294;
}
        break;
      case 119: /* hintlist1 ::= hintlist1 onehint */
{
	if (!yymsp[-1].minor.yy294) {
		yymsp[-1].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	assert(yymsp[0].minor.yy60);
	yymsp[-1].minor.yy294->push_back(yymsp[0].minor.yy60);
	yygotominor.yy294 = yymsp[-1].minor.yy294;
}
        break;
      case 120: /* hintlist1 ::= onehint */
{
	assert(yymsp[0].minor.yy60);
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	assert(yymsp[0].minor.yy60);
	yygotominor.yy294->push_back(yymsp[0].minor.yy60);
}
        break;
      case 121: /* onehint ::= ID LP hintexprlist RP */
{
	if (!yymsp[-1].minor.yy294) {
		yymsp[-1].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	SyntaxTree::Expr* hintExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_LIST);

	hintExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-3].minor.yy0);

	hintExpr->next_ = yymsp[-1].minor.yy294;
	hintExpr->startToken_ = yymsp[-2].minor.yy0;
	hintExpr->endToken_ = yymsp[0].minor.yy0;

	yygotominor.yy60 = hintExpr;
}
        break;
      case 124: /* hintexprlist1 ::= hintexprlist1 hintexpr */
{
	if (!yymsp[-1].minor.yy294) {
		yymsp[-1].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	yymsp[-1].minor.yy294->push_back(yymsp[0].minor.yy60);
	yygotominor.yy294 = yymsp[-1].minor.yy294;
}
        break;
      case 125: /* hintexprlist1 ::= hintexpr */
      case 184: /* limit_opt ::= LIMIT expr */ yytestcase(yyruleno==184);
      case 275: /* nexprlist ::= expr */ yytestcase(yyruleno==275);
{
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yygotominor.yy294->push_back(yymsp[0].minor.yy60);
}
        break;
      case 126: /* hintexpr ::= term */
      case 145: /* from ::= FROM seltabtree */ yytestcase(yyruleno==145);
      case 200: /* expr ::= term */ yytestcase(yyruleno==200);
{
	yygotominor.yy60 = yymsp[0].minor.yy60;
}
        break;
      case 127: /* hintexpr ::= MINUS INTEGER */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	yygotominor.yy60->startToken_ = yymsp[-1].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;

	util::String str(yymsp[-1].minor.yy0.value_, yymsp[-1].minor.yy0.value_ + yymsp[-1].minor.yy0.size_, parser->getSQLAllocator());
	str.append(yymsp[0].minor.yy0.value_, yymsp[0].minor.yy0.size_);
	int64_t int64Value;
	bool succeeded = SQLProcessor::ValueUtils::toLong(
			str.c_str(), str.size(), int64Value);
	if (succeeded) {
		yygotominor.yy60->value_ = TupleValue(int64Value);
	}
	else {
		double doubleValue;
		bool succeeded = SQLProcessor::ValueUtils::toDouble(
				str.c_str(), str.size(), doubleValue);
		if (succeeded) {
			yygotominor.yy60->value_ = TupleValue(doubleValue);
		}
		else {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
								   yymsp[0].minor.yy0, "Invalid constant value");
		}
	}
}
        break;
      case 128: /* hintexpr ::= MINUS FLOAT */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	yygotominor.yy60->startToken_ = yymsp[-1].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;

	util::String str(yymsp[-1].minor.yy0.value_, yymsp[-1].minor.yy0.value_ + yymsp[-1].minor.yy0.size_, parser->getSQLAllocator());
	str.append(yymsp[0].minor.yy0.value_, yymsp[0].minor.yy0.size_);
	double doubleValue;
	bool succeeded = SQLProcessor::ValueUtils::toDouble(
			str.c_str(), str.size(), doubleValue);
	if (succeeded) {
		yygotominor.yy60->value_ = TupleValue(doubleValue);
	}
	else {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
							   yymsp[0].minor.yy0, "Invalid constant value");
	}
}
        break;
      case 129: /* hintexpr ::= LP hintexprlist1 RP */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0: Token */
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_LIST);
	yygotominor.yy60->next_ = yymsp[-1].minor.yy294;
	yygotominor.yy60->startToken_ = yymsp[-2].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 130: /* hintexpr ::= ID */
      case 203: /* expr ::= ID */ yytestcase(yyruleno==203);
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_COLUMN);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);
	if (!yygotominor.yy60->qName_->name_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Zero-length delimited identifier");
	}
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
}
        break;
      case 131: /* hintexpr ::= nm DOT nm */
      case 204: /* expr ::= nm DOT nm */ yytestcase(yyruleno==204);
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_COLUMN);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-2].minor.yy0, &yymsp[0].minor.yy0);
	if (!yygotominor.yy60->qName_->name_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Zero-length delimited identifier");
	}
	yygotominor.yy60->startToken_ = yymsp[-2].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 132: /* hintexpr ::= nm DOT nm DOT nm */
      case 205: /* expr ::= nm DOT nm DOT nm */ yytestcase(yyruleno==205);
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_COLUMN);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-4].minor.yy0, &yymsp[-2].minor.yy0, &yymsp[0].minor.yy0);
	if (!yygotominor.yy60->qName_->name_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Zero-length delimited identifier");
	}
	yygotominor.yy60->startToken_ = yymsp[-4].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 133: /* distinct ::= DISTINCT */
{yygotominor.yy168 = SyntaxTree::AGGR_OPT_DISTINCT;}
        break;
      case 134: /* distinct ::= ALL */
      case 135: /* distinct ::= */ yytestcase(yyruleno==135);
{yygotominor.yy168 = SyntaxTree::AGGR_OPT_ALL;}
        break;
      case 137: /* sclp ::= */
      case 183: /* limit_opt ::= */ yytestcase(yyruleno==183);
{
	yygotominor.yy294 = 0;
}
        break;
      case 138: /* selcollist ::= sclp expr as */
{
	if (!yymsp[-2].minor.yy294) {
		yymsp[-2].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	if (yymsp[0].minor.yy0.size_ > 0) {
		assert(yymsp[-1].minor.yy60);
		yymsp[-1].minor.yy60->aliasName_ = SyntaxTree::tokenToString(
				parser->getSQLAllocator(), yymsp[0].minor.yy0, true);
	}
	yygotominor.yy294 = yymsp[-2].minor.yy294;
	yygotominor.yy294->push_back(yymsp[-1].minor.yy60);
}
        break;
      case 139: /* selcollist ::= sclp STAR */
{
	SyntaxTree::Expr* expr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ALL_COLUMN);

	if (!yymsp[-1].minor.yy294) {
		yymsp[-1].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	yygotominor.yy294 = yymsp[-1].minor.yy294;
	yygotominor.yy294->push_back(expr);
}
        break;
      case 140: /* selcollist ::= sclp nm DOT STAR */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0:Token */
	SyntaxTree::Expr* expr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ALL_COLUMN);

	expr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-2].minor.yy0, NULL);
	if (!yymsp[-3].minor.yy294) {
		yymsp[-3].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	yygotominor.yy294 = yymsp[-3].minor.yy294;
	yygotominor.yy294->push_back(expr);
}
        break;
      case 143: /* as ::= */
{yygotominor.yy0.size_ = 0;}
        break;
      case 144: /* from ::= */
{
	yygotominor.yy60 = 0;
}
        break;
      case 146: /* stl_prefix ::= seltabtree joinop */
{
	assert(yymsp[-1].minor.yy60);
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_JOIN);
	yygotominor.yy60->joinOp_ = yymsp[0].minor.yy173;
	yygotominor.yy60->left_ = yymsp[-1].minor.yy60;
	yygotominor.yy60->right_ = NULL;
}
        break;
      case 147: /* stl_prefix ::= */
{ yygotominor.yy60 = 0; }
        break;
      case 148: /* seltabtree ::= stl_prefix nm dbnm as on_opt using_opt */
{
	SyntaxTree::QualifiedName* qName = NULL;
	if (!yymsp[-5].minor.yy60 && (yymsp[-1].minor.yy60 || yymsp[0].minor.yy294)) {
		if (yymsp[-1].minor.yy60) {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					yymsp[-1].minor.yy60->startToken_, "JOIN clause is required before ON");
		}
		else {
			GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					"JOIN clause is required before USING");
		}
	}
	if (yymsp[-3].minor.yy0.size_ > 0) {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-4].minor.yy0, &yymsp[-3].minor.yy0, NULL);
	}
	else {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-4].minor.yy0, NULL);
	}
	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), qName, NULL);
	int64_t nsId = parser->checkAndGetViewSelectStr(table);
	if (yymsp[-2].minor.yy0.size_ > 0) {
		table->aliasName_ = SyntaxTree::tokenToString(
				parser->getSQLAllocator(), yymsp[-2].minor.yy0, true);
	}
	else if (nsId != SyntaxTree::QualifiedName::TOP_NS_ID) {
		table->aliasName_ = ALLOC_NEW(parser->getSQLAllocator()) util::String(
				qName->table_->c_str(), parser->getSQLAllocator());
	}
	if (nsId != SyntaxTree::QualifiedName::TOP_NS_ID) {
		if (!table->qName_) {
			table->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
					parser->getSQLAllocator());
		}
		table->qName_->nsId_ = nsId;
	}
	if (!yymsp[-5].minor.yy60) {
		yymsp[-5].minor.yy60 = table;
	}
	else {
		assert(yymsp[-5].minor.yy60->op_ == SQLType::EXPR_JOIN);
		assert(yymsp[-5].minor.yy60->right_ == NULL);
		yymsp[-5].minor.yy60->right_ = table;

		yymsp[-5].minor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
		yymsp[-5].minor.yy60->next_->push_back(yymsp[-1].minor.yy60);  
		if (yymsp[0].minor.yy294) {
			yymsp[-5].minor.yy60->next_->reserve(1 + yymsp[0].minor.yy294->size());
			yymsp[-5].minor.yy60->next_->insert(yymsp[-5].minor.yy60->next_->end(), yymsp[0].minor.yy294->begin(), yymsp[0].minor.yy294->end());
		}
		else {
			yymsp[-5].minor.yy60->next_->push_back(NULL);
		}
	}
	yygotominor.yy60 = yymsp[-5].minor.yy60;
	parser->tableList_.push_back(table);
}
        break;
      case 149: /* seltabtree ::= stl_prefix nm dbnm LP exprlist RP as on_opt using_opt */
{
	SyntaxTree::QualifiedName* qName = NULL;
	if (!yymsp[-8].minor.yy60 && (yymsp[-1].minor.yy60 || yymsp[0].minor.yy294)) {
		if (yymsp[-1].minor.yy60) {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					yymsp[-1].minor.yy60->startToken_, "JOIN clause is required before ON");
		}
		else {
			GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					"JOIN clause is required before USING");
		}
	}
	if (yymsp[-6].minor.yy0.size_ > 0) {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-7].minor.yy0, &yymsp[-6].minor.yy0, NULL);
	}
	else {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(),
				parser->viewNsId_, NULL, &yymsp[-7].minor.yy0, NULL);
	}
	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), qName, NULL);
	int64_t nsId = parser->checkAndGetViewSelectStr(table);
	if (yymsp[-2].minor.yy0.size_ > 0) {
		table->aliasName_ = SyntaxTree::tokenToString(
				parser->getSQLAllocator(), yymsp[-2].minor.yy0, true);
	}
	else if (nsId != SyntaxTree::QualifiedName::TOP_NS_ID) {
		table->aliasName_ = ALLOC_NEW(parser->getSQLAllocator()) util::String(
				qName->table_->c_str(), parser->getSQLAllocator());
	}
	if (nsId != SyntaxTree::QualifiedName::TOP_NS_ID) {
		if (!table->qName_) {
			table->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
					parser->getSQLAllocator());
		}
		table->qName_->nsId_ = nsId;
	}
	if (yymsp[-4].minor.yy294) {
		table->next_ = yymsp[-4].minor.yy294;
	}
	if (!yymsp[-8].minor.yy60) {
		yymsp[-8].minor.yy60 = table;
	}
	else {
		assert(yymsp[-8].minor.yy60->op_ == SQLType::EXPR_JOIN);
		assert(yymsp[-8].minor.yy60->right_ == NULL);
		yymsp[-8].minor.yy60->right_ = table;

		yymsp[-8].minor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
		yymsp[-8].minor.yy60->next_->push_back(yymsp[-1].minor.yy60);  
		if (yymsp[0].minor.yy294) {
			yymsp[-8].minor.yy60->next_->reserve(1 + yymsp[0].minor.yy294->size());
			yymsp[-8].minor.yy60->next_->insert(yymsp[-8].minor.yy60->next_->end(), yymsp[0].minor.yy294->begin(), yymsp[0].minor.yy294->end());
		}
		else {
			yymsp[-8].minor.yy60->next_->push_back(NULL);
		}
	}
	yygotominor.yy60 = yymsp[-8].minor.yy60;
	parser->tableList_.push_back(table);
}
        break;
      case 150: /* seltabtree ::= stl_prefix LP select RP as on_opt using_opt */
{

	SyntaxTree::QualifiedName* qName = NULL;
	if (!yymsp[-6].minor.yy60 && (yymsp[-1].minor.yy60 || yymsp[0].minor.yy294)) {
		if (yymsp[-1].minor.yy60) {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					yymsp[-1].minor.yy60->startToken_, "JOIN clause is required before ON");
		}
		else {
			GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					"JOIN clause is required before USING");
		}
	}
	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
		parser->getSQLAllocator(), NULL, yymsp[-4].minor.yy158);
	if (yymsp[-2].minor.yy0.size_ > 0) {
		table->aliasName_ = SyntaxTree::tokenToString(
				parser->getSQLAllocator(), yymsp[-2].minor.yy0, true);
	}
	else {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-3].minor.yy0,
				"Subquery in FROM must have an alias");
	}
	if (!yymsp[-6].minor.yy60) {
		yymsp[-6].minor.yy60 = table;
	}
	else {
		assert(yymsp[-6].minor.yy60->op_ == SQLType::EXPR_JOIN);
		assert(yymsp[-6].minor.yy60->right_ == NULL);
		yymsp[-6].minor.yy60->right_ = table;

		yymsp[-6].minor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
		yymsp[-6].minor.yy60->next_->push_back(yymsp[-1].minor.yy60);  
		if (yymsp[0].minor.yy294) {
			yymsp[-6].minor.yy60->next_->reserve(1 + yymsp[0].minor.yy294->size());
			yymsp[-6].minor.yy60->next_->insert(yymsp[-6].minor.yy60->next_->end(), yymsp[0].minor.yy294->begin(), yymsp[0].minor.yy294->end());
		}
		else {
			yymsp[-6].minor.yy60->next_->push_back(NULL);
		}
	}
	yygotominor.yy60 = yymsp[-6].minor.yy60;
	parser->tableList_.push_back(table);

	if (yymsp[-4].minor.yy158 && yymsp[-4].minor.yy158->right_ && yymsp[-4].minor.yy158->right_->hintList_) {
		SQLToken token;
		if (yymsp[-4].minor.yy158->right_->hintList_->size() > 0) {
			token = yymsp[-4].minor.yy158->right_->hintList_->at(0)->startToken_;
		}
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				token, "Invalid hint found");
	}
}
        break;
      case 151: /* seltabtree ::= stl_prefix LP seltabtree RP as on_opt using_opt */
{

	SyntaxTree::QualifiedName* qName = NULL;
	if (!yymsp[-6].minor.yy60 && (yymsp[-1].minor.yy60 || yymsp[0].minor.yy294)) {
		if (yymsp[-1].minor.yy60) {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					yymsp[-1].minor.yy60->startToken_, "JOIN clause is required before ON");
		}
		else {
			GS_THROW_USER_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
					"JOIN clause is required before USING");
		}
	}
	if (yymsp[-6].minor.yy60 == 0 && (yymsp[-2].minor.yy0.size_ == 0) && yymsp[-1].minor.yy60==0 && yymsp[0].minor.yy294==0) {
		yygotominor.yy60 = yymsp[-4].minor.yy60;
	}
	else {
		if (yymsp[-2].minor.yy0.size_ > 0) {
			yymsp[-4].minor.yy60->aliasName_ = SyntaxTree::tokenToString(
					parser->getSQLAllocator(), yymsp[-2].minor.yy0, true);
		}

		if (!yymsp[-6].minor.yy60) {
			yymsp[-6].minor.yy60 = yymsp[-4].minor.yy60;
		}
		else {
			assert(yymsp[-6].minor.yy60->op_ == SQLType::EXPR_JOIN);
			assert(yymsp[-6].minor.yy60->right_ == NULL);
			yymsp[-6].minor.yy60->right_ = yymsp[-4].minor.yy60;

			yymsp[-6].minor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
					SyntaxTree::ExprList(parser->getSQLAllocator());
			yymsp[-6].minor.yy60->next_->push_back(yymsp[-1].minor.yy60);  
			if (yymsp[0].minor.yy294) {
				yymsp[-6].minor.yy60->next_->reserve(1 + yymsp[0].minor.yy294->size());
				yymsp[-6].minor.yy60->next_->insert(yymsp[-6].minor.yy60->next_->end(), yymsp[0].minor.yy294->begin(), yymsp[0].minor.yy294->end());
			}
			else {
				yymsp[-6].minor.yy60->next_->push_back(NULL);
			}
		}
		yygotominor.yy60 = yymsp[-6].minor.yy60;
	}
}
        break;
      case 152: /* dbnm ::= */
{yygotominor.yy0.value_ = 0; yygotominor.yy0.size_ = 0;}
        break;
      case 154: /* fullname ::= nm dbnm */
{
	SyntaxTree::QualifiedName* qName = NULL;
	if (yymsp[0].minor.yy0.size_ > 0) {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, &yymsp[-1].minor.yy0, &yymsp[0].minor.yy0, NULL);
	}
	else {
		qName = SyntaxTree::QualifiedName::makeQualifiedName(
				parser->getSQLAllocator(), parser->viewNsId_, NULL, &yymsp[-1].minor.yy0, NULL);
	}
	yygotominor.yy295 = qName;
}
        break;
      case 155: /* joinop ::= COMMA|JOIN */
      case 156: /* joinop ::= INNER JOIN */ yytestcase(yyruleno==156);
      case 157: /* joinop ::= CROSS JOIN */ yytestcase(yyruleno==157);
{
	yygotominor.yy173 = SQLType::JOIN_INNER;
}
        break;
      case 158: /* joinop ::= LEFT JOIN */
      case 159: /* joinop ::= LEFT OUTER JOIN */ yytestcase(yyruleno==159);
{
	yygotominor.yy173 = SQLType::JOIN_LEFT_OUTER;
}
        break;
      case 160: /* joinop ::= RIGHT JOIN */
      case 161: /* joinop ::= RIGHT OUTER JOIN */ yytestcase(yyruleno==161);
{
	yygotominor.yy173 = SQLType::JOIN_RIGHT_OUTER;
}
        break;
      case 162: /* joinop ::= FULL JOIN */
{
	SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
			"FULL JOIN is not supported");
	yygotominor.yy173 = SQLType::JOIN_FULL_OUTER;
}
        break;
      case 163: /* joinop ::= FULL OUTER JOIN */
{
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"FULL OUTER JOIN is not supported");
	yygotominor.yy173 = SQLType::JOIN_FULL_OUTER;
}
        break;
      case 164: /* joinop ::= NATURAL JOIN */
      case 165: /* joinop ::= NATURAL INNER JOIN */ yytestcase(yyruleno==165);
      case 166: /* joinop ::= NATURAL CROSS JOIN */ yytestcase(yyruleno==166);
{
	yygotominor.yy173 = SQLType::JOIN_NATURAL_INNER;
}
        break;
      case 167: /* joinop ::= NATURAL LEFT JOIN */
      case 168: /* joinop ::= NATURAL LEFT OUTER JOIN */ yytestcase(yyruleno==168);
{
	yygotominor.yy173 = SQLType::JOIN_NATURAL_LEFT_OUTER;
}
        break;
      case 169: /* joinop ::= NATURAL RIGHT JOIN */
      case 170: /* joinop ::= NATURAL RIGHT OUTER JOIN */ yytestcase(yyruleno==170);
{
	yygotominor.yy173 = SQLType::JOIN_NATURAL_RIGHT_OUTER;
}
        break;
      case 171: /* on_opt ::= ON expr */
      case 182: /* having_opt ::= HAVING expr */ yytestcase(yyruleno==182);
      case 188: /* where_opt ::= WHERE expr */ yytestcase(yyruleno==188);
{yygotominor.yy60 = yymsp[0].minor.yy60;}
        break;
      case 172: /* on_opt ::= */
      case 181: /* having_opt ::= */ yytestcase(yyruleno==181);
      case 187: /* where_opt ::= */ yytestcase(yyruleno==187);
      case 269: /* case_else ::= */ yytestcase(yyruleno==269);
      case 271: /* case_operand ::= */ yytestcase(yyruleno==271);
{yygotominor.yy60 = 0;}
        break;
      case 173: /* using_opt ::= USING LP idlist RP */
      case 197: /* inscollist_opt ::= LP idlist RP */ yytestcase(yyruleno==197);
{yygotominor.yy294 = yymsp[-1].minor.yy294;}
        break;
      case 177: /* sortlist ::= sortlist COMMA expr sortascending */
{
	if (!yymsp[-3].minor.yy294) {
		yymsp[-3].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	yymsp[-1].minor.yy60->sortAscending_ = yymsp[0].minor.yy371;
	yymsp[-3].minor.yy294->push_back(yymsp[-1].minor.yy60);
	yygotominor.yy294 = yymsp[-3].minor.yy294;
}
        break;
      case 178: /* sortlist ::= expr sortascending */
{
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yymsp[-1].minor.yy60->sortAscending_ = yymsp[0].minor.yy371;
	yygotominor.yy294->push_back(yymsp[-1].minor.yy60);
}
        break;
      case 185: /* limit_opt ::= LIMIT expr OFFSET expr */
{
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yygotominor.yy294->push_back(yymsp[-2].minor.yy60);
	yygotominor.yy294->push_back(yymsp[0].minor.yy60);
}
        break;
      case 186: /* limit_opt ::= LIMIT expr COMMA expr */
{
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yygotominor.yy294->push_back(yymsp[0].minor.yy60);  
	yygotominor.yy294->push_back(yymsp[-2].minor.yy60);  
}
        break;
      case 189: /* cmd ::= hint_opt DELETE hint_opt FROM fullname as where_opt */
{
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
		parser->getSQLAllocator(), SyntaxTree::CMD_DELETE);
	select->targetName_ = yymsp[-2].minor.yy295;
	select->where_ = yymsp[0].minor.yy60;
	if (yymsp[-6].minor.yy294 || yymsp[-4].minor.yy294) {
		select->hintList_ = yymsp[-6].minor.yy294 ? yymsp[-6].minor.yy294 : yymsp[-4].minor.yy294;
	}
	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), select->targetName_, NULL);
	if (yymsp[-1].minor.yy0.size_ > 0) {
		table->aliasName_ = SyntaxTree::tokenToString(
				parser->getSQLAllocator(), yymsp[-1].minor.yy0, true);
	}
	parser->tableList_.push_back(table);

	select->from_ = table;

	parser->setTopSelect(select);

	parser->currentSelect_ = select;
	if (parser->childrenList_.size() > 0) {
		for (size_t pos = 0; pos < parser->childrenList_.size(); ++pos) {
			parser->childrenList_[pos]->parent_ = select;
		}
		parser->childrenList_.clear();
	}
}
        break;
      case 190: /* cmd ::= hint_opt UPDATE hint_opt orconf fullname as SET setlist where_opt */
{
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
		parser->getSQLAllocator(), SyntaxTree::CMD_UPDATE);
	select->targetName_ = yymsp[-4].minor.yy295;
	select->updateSetList_ = yymsp[-1].minor.yy294;
	select->where_ = yymsp[0].minor.yy60;
	select->cmdOptionValue_ = yymsp[-5].minor.yy428;
	if (yymsp[-8].minor.yy294 || yymsp[-6].minor.yy294) {
		select->hintList_ = yymsp[-8].minor.yy294 ? yymsp[-8].minor.yy294 : yymsp[-6].minor.yy294;
	}
	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), select->targetName_, NULL);
	if (yymsp[-3].minor.yy0.size_ > 0) {
		table->aliasName_ = SyntaxTree::tokenToString(
				parser->getSQLAllocator(), yymsp[-3].minor.yy0, true);
	}
	parser->tableList_.push_back(table);

	select->from_ = table;

	parser->setTopSelect(select);

	parser->currentSelect_ = select;
	if (parser->childrenList_.size() > 0) {
		for (size_t pos = 0; pos < parser->childrenList_.size(); ++pos) {
			parser->childrenList_[pos]->parent_ = select;
		}
		parser->childrenList_.clear();
	}
}
        break;
      case 191: /* setlist ::= setlist COMMA nm EQ expr */
{
	if (!yymsp[-4].minor.yy294) {
		yymsp[-4].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	SyntaxTree::Expr* opExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::OP_EQ);

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_COLUMN);

	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"Column name must not be empty");
	}
	opExpr->left_ = nameExpr;
	opExpr->right_ = yymsp[0].minor.yy60;
	yygotominor.yy294 = yymsp[-4].minor.yy294;
	yygotominor.yy294->push_back(opExpr);
}
        break;
      case 192: /* setlist ::= nm EQ expr */
{
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	SyntaxTree::Expr* opExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::OP_EQ);

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_COLUMN);

	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[-2].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-2].minor.yy0,
				"Column name must not be empty");
	}
	opExpr->left_ = nameExpr;
	opExpr->right_ = yymsp[0].minor.yy60;
	yygotominor.yy294->push_back(opExpr);
}
        break;
      case 193: /* cmd ::= hint_opt insert_cmd hint_opt INTO fullname inscollist_opt select */
{
	SyntaxTree::Select* select = SyntaxTree::Select::makeSelect(
			parser->getSQLAllocator(), SyntaxTree::CMD_INSERT);
	select->targetName_ = yymsp[-2].minor.yy295;
	select->insertSet_ = yymsp[0].minor.yy158;
	select->insertList_ = yymsp[-1].minor.yy294;
	select->cmdOptionValue_ = yymsp[-5].minor.yy78;
	if (yymsp[-6].minor.yy294 || yymsp[-4].minor.yy294) {
		select->hintList_ = yymsp[-6].minor.yy294 ? yymsp[-6].minor.yy294 : yymsp[-4].minor.yy294;
	}

	SyntaxTree::Expr* table = SyntaxTree::Expr::makeTable(
			parser->getSQLAllocator(), select->targetName_, NULL);
	parser->tableList_.push_back(table);

	parser->setTopSelect(select);

	parser->currentSelect_ = select;
	if (parser->childrenList_.size() > 0) {
		for (size_t pos = 0; pos < parser->childrenList_.size(); ++pos) {
			parser->childrenList_[pos]->parent_ = select;
		}
		parser->childrenList_.clear();
	}

	if (yymsp[0].minor.yy158 && yymsp[0].minor.yy158->right_ && yymsp[0].minor.yy158->right_->hintList_) {
		SQLToken token;
		if (yymsp[0].minor.yy158->right_->hintList_->size() > 0) {
			token = yymsp[0].minor.yy158->right_->hintList_->at(0)->startToken_;
		}
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				token, "Invalid hint found");
	}
}
        break;
      case 194: /* insert_cmd ::= INSERT orconf */
{yygotominor.yy78 = yymsp[0].minor.yy428;}
        break;
      case 195: /* insert_cmd ::= REPLACE */
{yygotominor.yy78 = SyntaxTree::RESOLVETYPE_REPLACE;}
        break;
      case 198: /* idlist ::= idlist COMMA nm */
{
	if (!yymsp[-2].minor.yy294) {
		yymsp[-2].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_COLUMN);

	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Column name must not be empty");
	}
	yygotominor.yy294 = yymsp[-2].minor.yy294;
	yygotominor.yy294->push_back(nameExpr);
}
        break;
      case 199: /* idlist ::= nm */
{
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());

	SyntaxTree::Expr* nameExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_COLUMN);

	nameExpr->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), parser->viewNsId_, NULL, NULL, &yymsp[0].minor.yy0);

	if (!nameExpr->qName_->name_ || nameExpr->qName_->name_->size() == 0) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Column name must not be empty");
	}
	yygotominor.yy294->push_back(nameExpr);
}
        break;
      case 201: /* expr ::= LP expr RP */
{
	/* yymsp[-2].minor.yy0, yymsp[0].minor.yy0: Token */
	yygotominor.yy60 = yymsp[-1].minor.yy60;
	yygotominor.yy60->startToken_ = yymsp[-2].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 202: /* term ::= NULL */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	yygotominor.yy60->value_ = TupleValue(&SyntaxTree::NULL_VALUE_RAW_DATA, TupleList::TYPE_ANY);
}
        break;
      case 206: /* term ::= INTEGER */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;

	int64_t int64Value;
	bool succeeded = SQLProcessor::ValueUtils::toLong(
		yymsp[0].minor.yy0.value_, yymsp[0].minor.yy0.size_, int64Value);
	if (succeeded) {
		yygotominor.yy60->value_ = TupleValue(int64Value);
	}
	else {
		double doubleValue;
		bool succeeded = SQLProcessor::ValueUtils::toDouble(
				yymsp[0].minor.yy0.value_, yymsp[0].minor.yy0.size_, doubleValue);
		if (succeeded) {
			yygotominor.yy60->value_ = TupleValue(doubleValue);
		}
		else {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
								   yymsp[0].minor.yy0, "Invalid constant value");
		}
	}
}
        break;
      case 207: /* term ::= FLOAT */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);

	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
	double doubleValue;
	bool succeeded = SQLProcessor::ValueUtils::toDouble(
			yymsp[0].minor.yy0.value_, yymsp[0].minor.yy0.size_, doubleValue);
	if (succeeded) {
		yygotominor.yy60->value_ = TupleValue(doubleValue);
	}
	else {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
							   yymsp[0].minor.yy0, "Invalid constant value");
	}
}
        break;
      case 208: /* term ::= TRUE */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	yygotominor.yy60->value_ = TupleValue(true);
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
}
        break;
      case 209: /* term ::= FALSE */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	yygotominor.yy60->value_ = TupleValue(false);
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
}
        break;
      case 210: /* term ::= BLOB */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	assert(yymsp[0].minor.yy0.size_ >= 3); 
	util::String hexStr(yymsp[0].minor.yy0.value_ + 2, yymsp[0].minor.yy0.value_ + yymsp[0].minor.yy0.size_ - 1, parser->getSQLAllocator());
	util::XArray<char> buffer(parser->getSQLAllocator());
	char temp = 0;
	buffer.assign(hexStr.size() / 2 + 1, temp);
	size_t byteSize = util::HexConverter::decode(buffer.data(), hexStr.c_str(), hexStr.size());
	yygotominor.yy60->value_ = SyntaxTree::makeBlobValue(
		parser->getVarContext(), buffer.data(), byteSize);
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
}
        break;
      case 211: /* term ::= STRING */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	util::String* str = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[0].minor.yy0, true);
	if (!str) {
		str = ALLOC_NEW(parser->getSQLAllocator())
				util::String("", parser->getSQLAllocator());
	}
	yygotominor.yy60->value_ = SyntaxTree::makeStringValue(
			parser->getSQLAllocator(), str->c_str(), str->size());
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
}
        break;
      case 212: /* expr ::= VARIABLE */
{
	/* yymsp[0].minor.yy0: Token */
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_PLACEHOLDER);
	yygotominor.yy60->placeHolderCount_ = ++parser->placeHolderCount_;
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
}
        break;
      case 213: /* expr ::= CAST LP expr AS typetoken RP */
{
	/* yymsp[-5].minor.yy0, yymsp[0].minor.yy0: Token */

	util::String* typeStr = SyntaxTree::tokenToString(
			parser->getSQLAllocator(), yymsp[-1].minor.yy0, false);
	if (!typeStr) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"Type name must not be empty");
	}
	TupleList::TupleColumnType colType = SyntaxTree::toColumnType(typeStr->c_str());
	if (colType == TupleList::TYPE_NULL) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"Syntax error at or near \"" << typeStr->c_str() << "\"");
	}
	SyntaxTree::Expr *typeExpr = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_TYPE);
	typeExpr->columnType_ = colType;

	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(*parser, 
			SQLType::OP_CAST, yymsp[-3].minor.yy60, typeExpr);
	yygotominor.yy60->startToken_ = yymsp[-5].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 214: /* expr ::= EXTRACT LP field COMMA exprlist RP */
      case 215: /* expr ::= TIMESTAMPADD LP field COMMA exprlist RP */ yytestcase(yyruleno==215);
      case 216: /* expr ::= TIMESTAMPDIFF LP field COMMA exprlist RP */ yytestcase(yyruleno==216);
      case 217: /* expr ::= TIMESTAMP_TRUNC LP field COMMA exprlist RP */ yytestcase(yyruleno==217);
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_FUNCTION);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), 0, NULL, NULL, &yymsp[-5].minor.yy0);

	assert(yymsp[-3].minor.yy60);
	yygotominor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yygotominor.yy60->next_->push_back(yymsp[-3].minor.yy60);
	yygotominor.yy60->next_->reserve(yygotominor.yy60->next_->size() + yymsp[-1].minor.yy294->size());
	std::copy(yymsp[-1].minor.yy294->begin(), yymsp[-1].minor.yy294->end(), std::back_inserter(*yygotominor.yy60->next_));
	yygotominor.yy60->startToken_ = yymsp[-5].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 218: /* field ::= YEAR|MONTH|DAY|HOUR|MINUTE|SECOND|MILLISECOND|DAY_OF_WEEK|DAY_OF_YEAR */
{
	util::DateTime::FieldType fieldType;
	switch (yymsp[0].minor.yy0.id_) {
	case TK_YEAR:
		fieldType = util::DateTime::FIELD_YEAR;
		break;
	case TK_MONTH:
		fieldType = util::DateTime::FIELD_MONTH;
		break;
	case TK_DAY:
		fieldType  = util::DateTime::FIELD_DAY_OF_MONTH;
		break;
	case TK_HOUR:
		fieldType  = util::DateTime::FIELD_HOUR;
		break;
	case TK_MINUTE:
		fieldType  = util::DateTime::FIELD_MINUTE;
		break;
	case TK_SECOND:
		fieldType  = util::DateTime::FIELD_SECOND;
		break;
	case TK_MILLISECOND:
		fieldType  = util::DateTime::FIELD_MILLISECOND;
		break;
	case TK_DAY_OF_WEEK:
		fieldType  = util::DateTime::FIELD_DAY_OF_WEEK;
		break;
	case TK_DAY_OF_YEAR:
		fieldType  = util::DateTime::FIELD_DAY_OF_YEAR;
		break;
	default:
		yygotominor.yy60 = NULL;
		util::String* fieldStr = SyntaxTree::tokenToString(
				parser->getSQLAllocator(), yymsp[0].minor.yy0, false);
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[0].minor.yy0,
				"Unknwon field: " << fieldStr->c_str());
		break;
	}
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CONSTANT);
	yygotominor.yy60->value_ = TupleValue(static_cast<int64_t>(fieldType));
	yygotominor.yy60->startToken_ = yymsp[0].minor.yy0;
}
        break;
      case 219: /* expr ::= ID LP distinct exprlist RP window_opt */
{
	/* yymsp[-4].minor.yy0,yymsp[-1].minor.yy0: Token */
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_FUNCTION);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), 0, NULL, NULL, &yymsp[-5].minor.yy0);
	if (!yygotominor.yy60->qName_->name_) {
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-5].minor.yy0,
				"Zero-length delimited identifier");
	}
	yygotominor.yy60->next_ = yymsp[-2].minor.yy294;
	if (yymsp[-3].minor.yy168) {
#if SQL_PARSER_ENABLE_DISTINCT_WITHIN_AGGREGATE_FUNCTION
		yygotominor.yy60->aggrOpts_ = SyntaxTree::AGGR_OPT_DISTINCT;
#else
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-4].minor.yy0,
				"Not supported");
#endif
	}
	if (yymsp[0].minor.yy115) {
#if SQL_PARSER_ENABLE_WINDOW_FUNCTION
		if (yymsp[-3].minor.yy168) {
			SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-4].minor.yy0,
					"Use of DISTINCT is not allowed with the OVER clause");
		}
		yygotominor.yy60->windowOpt_ = yymsp[0].minor.yy115;
#else
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"Not supported");
#endif
	}
	yygotominor.yy60->startToken_ = yymsp[-5].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[-1].minor.yy0;
}
        break;
      case 220: /* expr ::= ID LP STAR RP window_opt */
{ 
	/* yymsp[-1].minor.yy0: Token */
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_FUNCTION);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), 0, NULL, NULL, &yymsp[-4].minor.yy0);

	yygotominor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
			ExprList(parser->getSQLAllocator());
	SyntaxTree::Expr* star = SyntaxTree::Expr::makeExpr(
			parser->getSQLAllocator(), SQLType::EXPR_ALL_COLUMN);
	yygotominor.yy60->next_->push_back(star);
	if (yymsp[0].minor.yy115) {
#if SQL_PARSER_ENABLE_WINDOW_FUNCTION
		yygotominor.yy60->windowOpt_ = yymsp[0].minor.yy115;
#else
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR, yymsp[-1].minor.yy0,
				"Not supported");
#endif
	}
	yygotominor.yy60->startToken_ = yymsp[-4].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[-1].minor.yy0;
}
        break;
      case 221: /* window_opt ::= */
{yygotominor.yy115 = 0;}
        break;
      case 222: /* window_opt ::= OVER LP partitionby_opt orderby_opt RP */
{
	yygotominor.yy115 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::WindowOption(parser->getSQLAllocator());

	yygotominor.yy115->partitionByList_ = yymsp[-2].minor.yy294;
	yygotominor.yy115->orderByList_ = yymsp[-1].minor.yy294;
}
        break;
      case 225: /* expr ::= expr AND expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::EXPR_AND, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 226: /* expr ::= expr OR expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::EXPR_OR, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 227: /* expr ::= expr LT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_LT, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 228: /* expr ::= expr GT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_GT, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 229: /* expr ::= expr GE expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_GE, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 230: /* expr ::= expr LE expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_LE, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 231: /* expr ::= expr EQ expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_EQ, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 232: /* expr ::= expr NE expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_NE, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 233: /* expr ::= expr BITAND expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_BIT_AND, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 234: /* expr ::= expr BITOR expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_BIT_OR, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 235: /* expr ::= expr LSHIFT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_SHIFT_LEFT, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 236: /* expr ::= expr RSHIFT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_SHIFT_RIGHT, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 237: /* expr ::= expr PLUS expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_ADD, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 238: /* expr ::= expr MINUS expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_SUBTRACT, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 239: /* expr ::= expr STAR expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_MULTIPLY, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 240: /* expr ::= expr SLASH expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_DIVIDE, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 241: /* expr ::= expr REM expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_REMAINDER, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 242: /* expr ::= expr CONCAT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_CONCAT, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 243: /* likeop ::= LIKE_KW|MATCH */
{
	yygotominor.yy472.operator_ = yymsp[0].minor.yy0;
	yygotominor.yy472.existNot_ = false;
}
        break;
      case 244: /* likeop ::= NOT LIKE_KW|MATCH */
{
	yygotominor.yy472.operator_ = yymsp[0].minor.yy0;
	yygotominor.yy472.existNot_ = true;
}
        break;
      case 245: /* expr ::= expr likeop expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_FUNCTION);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), 0, NULL, NULL, &yymsp[-1].minor.yy472.operator_);
	yygotominor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
			ExprList(parser->getSQLAllocator());
	yygotominor.yy60->next_->push_back(yymsp[0].minor.yy60); 
	yygotominor.yy60->next_->push_back(yymsp[-2].minor.yy60);
	if ( yymsp[-1].minor.yy472.existNot_ ) {
		SyntaxTree::Expr* likeBody = yygotominor.yy60;
		yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::OP_NOT);
		yygotominor.yy60->left_ = likeBody;
	}
	if (yymsp[-2].minor.yy60) { yygotominor.yy60->startToken_ = yymsp[-2].minor.yy60->startToken_; }
	if (yymsp[0].minor.yy60) { yygotominor.yy60->endToken_ = yymsp[0].minor.yy60->endToken_; }
}
        break;
      case 246: /* expr ::= expr likeop expr ESCAPE expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_FUNCTION);
	yygotominor.yy60->qName_ = SyntaxTree::QualifiedName::makeQualifiedName(
			parser->getSQLAllocator(), 0, NULL, NULL, &yymsp[-3].minor.yy472.operator_);

	yygotominor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
			ExprList(parser->getSQLAllocator());
	yygotominor.yy60->next_->push_back(yymsp[-2].minor.yy60); 
	yygotominor.yy60->next_->push_back(yymsp[-4].minor.yy60);
	yygotominor.yy60->next_->push_back(yymsp[0].minor.yy60);
	if ( yymsp[-3].minor.yy472.existNot_ ) {
		SyntaxTree::Expr* likeBody = yygotominor.yy60;
		yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::OP_NOT);
		yygotominor.yy60->left_ = likeBody;
	}
	if (yymsp[-4].minor.yy60) { yygotominor.yy60->startToken_ = yymsp[-4].minor.yy60->startToken_; }
	if (yymsp[0].minor.yy60) { yygotominor.yy60->endToken_ = yymsp[0].minor.yy60->endToken_; }
}
        break;
      case 247: /* expr ::= expr ISNULL */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
			*parser, SQLType::OP_IS_NULL, yymsp[-1].minor.yy60);
}
        break;
      case 248: /* expr ::= expr NOTNULL */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
			*parser, SQLType::OP_IS_NOT_NULL, yymsp[-1].minor.yy60);
}
        break;
      case 249: /* expr ::= expr NOT NULL */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
			*parser, SQLType::OP_IS_NOT_NULL, yymsp[-2].minor.yy60);
}
        break;
      case 250: /* expr ::= expr IS expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_IS, yymsp[-2].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 251: /* expr ::= expr IS NOT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::OP_IS_NOT, yymsp[-3].minor.yy60, yymsp[0].minor.yy60);
}
        break;
      case 252: /* expr ::= NOT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
			*parser, SQLType::OP_NOT, yymsp[0].minor.yy60);
}
        break;
      case 253: /* expr ::= BITNOT expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
			*parser, SQLType::OP_BIT_NOT, yymsp[0].minor.yy60);
}
        break;
      case 254: /* expr ::= MINUS expr */
{
	if (yymsp[0].minor.yy60 && yymsp[0].minor.yy60->op_ == SQLType::EXPR_CONSTANT) {
		SQLToken T = yymsp[0].minor.yy60->startToken_;
		if (T.id_ == TK_INTEGER 
			&& (((yymsp[0].minor.yy60->value_.getType() == TupleList::TYPE_LONG)
					&& (yymsp[0].minor.yy60->value_.get<int64_t>() > 0))
				|| ((yymsp[0].minor.yy60->value_.getType() == TupleList::TYPE_DOUBLE)
					&& (yymsp[0].minor.yy60->value_.get<double>() > 0)))) {
			yygotominor.yy60 = yymsp[0].minor.yy60;
			util::String str(yymsp[-1].minor.yy0.value_, yymsp[-1].minor.yy0.value_ + yymsp[-1].minor.yy0.size_, parser->getSQLAllocator());
			str.append(T.value_, T.size_);
			int64_t int64Value;
			bool succeeded = SQLProcessor::ValueUtils::toLong(
				str.c_str(), str.size(), int64Value);
			if (succeeded) {
				yygotominor.yy60->value_ = TupleValue(int64Value);
			}
			else {
				double doubleValue;
				bool succeeded = SQLProcessor::ValueUtils::toDouble(
					str.c_str(), str.size(), doubleValue);
				if (succeeded) {
					yygotominor.yy60->value_ = TupleValue(doubleValue);
				}
				else {
					SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
										   T, "Invalid constant value");
				}
			}
		}
		else if (T.id_ == TK_FLOAT
				&& yymsp[0].minor.yy60->value_.getType() == TupleList::TYPE_DOUBLE
				&& yymsp[0].minor.yy60->value_.get<double>() > 0) {
			yygotominor.yy60 = yymsp[0].minor.yy60;
			util::String str(yymsp[-1].minor.yy0.value_, yymsp[-1].minor.yy0.value_ + yymsp[-1].minor.yy0.size_, parser->getSQLAllocator());
			str.append(T.value_, T.size_);
			double doubleValue;
			bool succeeded = SQLProcessor::ValueUtils::toDouble(
				str.c_str(), str.size(), doubleValue);
			if (succeeded) {
				yygotominor.yy60->value_ = TupleValue(doubleValue);
			}
			else {
				SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
									   T, "Invalid constant value");
			}
		}
		else {
			yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
					*parser, SQLType::OP_MINUS, yymsp[0].minor.yy60);
		}
	}
	else {
		yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
				*parser, SQLType::OP_MINUS, yymsp[0].minor.yy60);
	}
}
        break;
      case 255: /* expr ::= PLUS expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
			*parser, SQLType::OP_PLUS, yymsp[0].minor.yy60);
}
        break;
      case 258: /* expr ::= expr between_op expr AND expr */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_BETWEEN);
	yygotominor.yy60->next_ = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yygotominor.yy60->next_->reserve(3);
	yygotominor.yy60->next_->push_back(yymsp[-4].minor.yy60);
	yygotominor.yy60->next_->push_back(yymsp[-2].minor.yy60);
	yygotominor.yy60->next_->push_back(yymsp[0].minor.yy60);
	if (yymsp[-3].minor.yy428) {
		SyntaxTree::Expr* body = yygotominor.yy60;
		yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
				*parser, SQLType::OP_NOT, body);
	}
	if (yymsp[-4].minor.yy60) { yygotominor.yy60->startToken_ = yymsp[-4].minor.yy60->startToken_; }
	if (yymsp[0].minor.yy60) { yygotominor.yy60->endToken_ = yymsp[0].minor.yy60->startToken_; }
}
        break;
      case 261: /* expr ::= expr in_op LP exprlist RP */
{
	SyntaxTree::Expr* listExpr = SyntaxTree::Expr::makeExpr(
		parser->getSQLAllocator(), SQLType::EXPR_LIST);
	listExpr->next_ = yymsp[-1].minor.yy294;

	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::EXPR_IN, yymsp[-4].minor.yy60, listExpr);
	if (yymsp[-3].minor.yy428) {
		SyntaxTree::Expr* body = yygotominor.yy60;
		yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
				*parser, SQLType::OP_NOT, body);
	}
	if (yymsp[-4].minor.yy60) { yygotominor.yy60->startToken_ = yymsp[-4].minor.yy60->startToken_; }
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 262: /* expr ::= LP select RP */
{
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_SELECTION);
	yygotominor.yy60->subQuery_ = yymsp[-1].minor.yy158;

	yygotominor.yy60->startToken_ = yymsp[-2].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;

	if (yymsp[-1].minor.yy158 && yymsp[-1].minor.yy158->right_ && yymsp[-1].minor.yy158->right_->hintList_) {
		SQLToken token;
		if (yymsp[-1].minor.yy158->right_->hintList_->size() > 0) {
			token = yymsp[-1].minor.yy158->right_->hintList_->at(0)->startToken_;
		}
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				token, "Invalid hint found");
	}
}
        break;
      case 263: /* expr ::= expr in_op LP select RP */
{
	SyntaxTree::Expr* selectExpr = SyntaxTree::Expr::makeExpr(
		parser->getSQLAllocator(), SQLType::EXPR_SELECTION);
	selectExpr->subQuery_ = yymsp[-1].minor.yy158;

	yygotominor.yy60 = SyntaxTree::Expr::makeBinaryExpr(
			*parser, SQLType::EXPR_IN, yymsp[-4].minor.yy60, selectExpr);
	if (yymsp[-3].minor.yy428) {
		SyntaxTree::Expr* body = yygotominor.yy60;
		yygotominor.yy60 = SyntaxTree::Expr::makeUnaryExpr(
				*parser, SQLType::OP_NOT, body);
	}
	if (yymsp[-4].minor.yy60) { yygotominor.yy60->startToken_ = yymsp[-4].minor.yy60->startToken_; }
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;

	if (yymsp[-1].minor.yy158 && yymsp[-1].minor.yy158->right_ && yymsp[-1].minor.yy158->right_->hintList_) {
		SQLToken token;
		if (yymsp[-1].minor.yy158->right_->hintList_->size() > 0) {
			token = yymsp[-1].minor.yy158->right_->hintList_->at(0)->startToken_;
		}
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				token, "Invalid hint found");
	}
}
        break;
      case 264: /* expr ::= EXISTS LP select RP */
{
	/* yymsp[-3].minor.yy0, yymsp[0].minor.yy0: Token */
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_EXISTS);
	yygotominor.yy60->subQuery_ = yymsp[-1].minor.yy158;

	yygotominor.yy60->startToken_ = yymsp[-3].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;

	if (yymsp[-1].minor.yy158 && yymsp[-1].minor.yy158->right_ && yymsp[-1].minor.yy158->right_->hintList_) {
		SQLToken token;
		if (yymsp[-1].minor.yy158->right_->hintList_->size() > 0) {
			token = yymsp[-1].minor.yy158->right_->hintList_->at(0)->startToken_;
		}
		SQL_PARSER_THROW_ERROR(GS_ERROR_SQL_COMPILE_SYNTAX_ERROR,
				token, "Invalid hint found");
	}
}
        break;
      case 265: /* expr ::= CASE case_operand case_exprlist case_else END */
{


	/* yymsp[-4].minor.yy0, yymsp[0].minor.yy0: Token */
	yygotominor.yy60 = SyntaxTree::Expr::makeExpr(parser->getSQLAllocator(), SQLType::EXPR_CASE);
	yygotominor.yy60->next_ = yymsp[-2].minor.yy294;
	if (yymsp[-3].minor.yy60 && yygotominor.yy60->next_) {
		SyntaxTree::ExprList::iterator itr = yygotominor.yy60->next_->begin();
		size_t count = 0;
		for (; itr != yygotominor.yy60->next_->end(); ++itr, ++count) {
			if (((count % 2) == 0) && *itr) { 
				SyntaxTree::Expr* newExpr = SyntaxTree::Expr::makeExpr(
					parser->getSQLAllocator(), SQLType::OP_EQ);
				newExpr->left_ = yymsp[-3].minor.yy60;
				newExpr->right_ = (*itr);
				(*itr) = newExpr;
			}
		}
	}
	if (yymsp[-1].minor.yy60) {
		yygotominor.yy60->next_->push_back(yymsp[-1].minor.yy60);
	}
	yygotominor.yy60->startToken_ = yymsp[-4].minor.yy0;
	yygotominor.yy60->endToken_ = yymsp[0].minor.yy0;
}
        break;
      case 266: /* case_exprlist ::= case_exprlist WHEN expr THEN expr */
{
	if (!yymsp[-4].minor.yy294) {
		yymsp[-4].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	yymsp[-4].minor.yy294->push_back(yymsp[-2].minor.yy60);
	if (yymsp[0].minor.yy60) {
		yymsp[-4].minor.yy294->push_back(yymsp[0].minor.yy60);
	}
	yygotominor.yy294 = yymsp[-4].minor.yy294;
}
        break;
      case 267: /* case_exprlist ::= WHEN expr THEN expr */
{
	yygotominor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
			SyntaxTree::ExprList(parser->getSQLAllocator());
	yygotominor.yy294->push_back(yymsp[-2].minor.yy60);
	if (yymsp[0].minor.yy60) {
		yygotominor.yy294->push_back(yymsp[0].minor.yy60);
	}
}
        break;
      case 268: /* case_else ::= ELSE expr */
      case 270: /* case_operand ::= expr */ yytestcase(yyruleno==270);
{
	yygotominor.yy60 = yymsp[0].minor.yy60;
	if (yymsp[0].minor.yy60) {
		yygotominor.yy60->startToken_ = yymsp[0].minor.yy60->startToken_;
		yygotominor.yy60->endToken_ = yymsp[0].minor.yy60->endToken_;
	}
}
        break;
      case 274: /* nexprlist ::= nexprlist COMMA expr */
{
	if (!yymsp[-2].minor.yy294) {
		yymsp[-2].minor.yy294 = ALLOC_NEW(parser->getSQLAllocator())
				SyntaxTree::ExprList(parser->getSQLAllocator());
	}
	yymsp[-2].minor.yy294->push_back(yymsp[0].minor.yy60);
	yygotominor.yy294 = yymsp[-2].minor.yy294;
}
        break;
      default:
      /* (0) input ::= cmdlist */ yytestcase(yyruleno==0);
      /* (1) cmdlist ::= cmdlist ecmd */ yytestcase(yyruleno==1);
      /* (2) cmdlist ::= ecmd */ yytestcase(yyruleno==2);
      /* (3) ecmd ::= SEMI */ yytestcase(yyruleno==3);
      /* (4) ecmd ::= explain cmdx SEMI */ yytestcase(yyruleno==4);
      /* (10) trans_opt ::= */ yytestcase(yyruleno==10);
      /* (11) trans_opt ::= TRANSACTION */ yytestcase(yyruleno==11);
      /* (15) cmd ::= create_table */ yytestcase(yyruleno==15);
      /* (17) createkw ::= CREATE */ yytestcase(yyruleno==17);
      /* (42) cmd ::= create_virtual_table */ yytestcase(yyruleno==42);
      /* (55) signed ::= plus_num */ yytestcase(yyruleno==55);
      /* (56) signed ::= minus_num */ yytestcase(yyruleno==56);
      /* (68) cmd ::= create_view */ yytestcase(yyruleno==68);
        break;
			};
			yygoto = yyRuleInfo[yyruleno].lhs;
			yysize = yyRuleInfo[yyruleno].nrhs;
			yyidx -= yysize;
			yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(SQLParser_YYCODETYPE)yygoto);
			if( yyact < SQLParser_YYNSTATE ){
#ifdef NDEBUG
				/* If we are not debugging and the reduce action popped at least
				 ** one element off the stack, then we can push the new element back
				 ** onto the stack here, and skip the stack overflow test in yy_shift().
				 ** That gives a significant speed improvement. */
				if( yysize ){
					yyidx++;
					yymsp -= yysize-1;
					yymsp->stateno = (SQLParser_YYACTIONTYPE)yyact;
					yymsp->major = (SQLParser_YYCODETYPE)yygoto;
					yymsp->minor = yygotominor;
				}else
#endif
				{
					yy_shift(yyact,yygoto,&yygotominor);
				}
			}else{
				assert( yyact == SQLParser_YYNSTATE + SQLParser_YYNRULE + 1 );
				yy_accept();
			}
		}

		/*
		 ** The following code executes when the parse fails
		 */
#ifndef SQLParser_YYNOERRORRECOVERY
		void yy_parse_failed(){
#ifndef NDEBUG
			if( yyTraceFILE ){
				*yyTraceFILE << yyTracePrompt << "Fail!" << std::endl;
			}
#endif
			while( yyidx>=0 ) yy_pop_parser_stack();
			/* Here code is inserted which will be executed whenever the
			 ** parser fails */
		}
#endif /* SQLParser_YYNOERRORRECOVERY */

		/*
		 ** The following code executes when a syntax error first occurs.
		 */
		void yy_syntax_error(
			int32_t yymajor,                   /* The major type of the error token */
			SQLParser_YYMINORTYPE yyminor            /* The minor type of the error token */
			){
#define TOKEN (yyminor.yy0)

	if (TOKEN.value_[0]) {
		util::String token(TOKEN.value_, TOKEN.size_, parser->getSQLAllocator());
		assert(parser->inputSql_ != NULL);
		size_t line = 0;
		size_t column = 0;
		SyntaxTree::countLineAndColumnFromToken(
			parser->inputSql_, TOKEN, line, column);
		util::NormalOStringStream ss;
		ss << "Syntax error at or near \"" << token.c_str()
			<< "\" (line=" << line << ", column=" << column << ")";
		parser->setError(ss.str().c_str());
	} else {
		parser->setError("Syntax error before finishing parse");
	}
	parser->parseState_ = SQLParserContext::PARSESTATE_END;
		}

		/*
		 ** The following is executed when the parser accepts
		 */
		void yy_accept(){
#ifndef NDEBUG
			if( yyTraceFILE ){
				*yyTraceFILE << yyTracePrompt << "Accept!" << std::endl;
			}
#endif
			while( yyidx>=0 ) yy_pop_parser_stack();
			/* Here code is inserted which will be executed whenever the
			 ** parser accepts */
		}

		/* The main parser program.
		 ** The first argument is a pointer to a structure obtained from
		 ** "SQLParserAlloc" which describes the current state of the parser.
		 ** The second argument is the major token number.  The third is
		 ** the minor token.  The fourth optional argument is whatever the
		 ** user wants (and specified in the grammar) and is available for
		 ** use by the action routines.
		 **
		 ** Inputs:
		 ** <ul>
		 ** <li> A pointer to the parser (an opaque structure.)
		 ** <li> The major token number.
		 ** <li> The minor token number.
		 ** <li> An option argument of a grammar-specified type.
		 ** </ul>
		 **
		 ** Outputs:
		 ** None.
		 */
	public:
		void Execute(
			int32_t yymajor,                 /* The major token code number */
			SQLParserTOKENTYPE &yyminor       /* The value for the token */
			SQLParserARG_PDECL               /* Optional %extra_argument parameter */
			){
			SQLParser_YYMINORTYPE yyminorunion;
			int32_t yyact;            /* The parser action. */
			int32_t yyendofinput;     /* True if we are at the end of input */
#ifdef SQLParser_YYERRORSYMBOL
			int32_t yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif

			/* (re)initialize the parser, if necessary */
			if( yyidx<0 ){
#if SQLParser_YYSTACKDEPTH<=0
				if( yystksz <=0 ){
					/*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
					yyminorunion = SQLParser_yyzerominor;
					yyStackOverflow(&yyminorunion);
					return;
				}
#endif
				yyidx = 0;
				yyerrcnt = -1;
				yystack[0].stateno = 0;
				yystack[0].major = 0;
			}
			yyminorunion.yy0 = yyminor;
			yyendofinput = (yymajor==0);
			SQLParserARG_STORE;

#ifndef NDEBUG
			if( yyTraceFILE ){
				*yyTraceFILE << yyTracePrompt <<
				  "Input " << yyTokenName[yymajor] << std::endl;
			}
#endif

			do{
				yyact = yy_find_shift_action((SQLParser_YYCODETYPE)yymajor);
				if( yyact<SQLParser_YYNSTATE ){
					assert( !yyendofinput );  /* Impossible to shift the $ token */
					yy_shift(yyact,yymajor,&yyminorunion);
					yyerrcnt--;
					yymajor = SQLParser_YYNOCODE;
				}else if( yyact < SQLParser_YYNSTATE + SQLParser_YYNRULE ){
					yy_reduce(yyact-SQLParser_YYNSTATE);
				}else{
					assert( yyact == SQLParser_YY_ERROR_ACTION );
#ifdef SQLParser_YYERRORSYMBOL
					int32_t yymx;
#endif
#ifndef NDEBUG
					if( yyTraceFILE ){
						*yyTraceFILE << yyTracePrompt <<
						  "Syntax Error!" << std::endl;
					}
#endif
#ifdef SQLParser_YYERRORSYMBOL
					/* A syntax error has occurred.
					 ** The response to an error depends upon whether or not the
					 ** grammar defines an error token "ERROR".
					 **
					 ** This is what we do if the grammar does define ERROR:
					 **
					 **  * Call the %syntax_error function.
					 **
					 **  * Begin popping the stack until we enter a state where
					 **    it is legal to shift the error symbol, then shift
					 **    the error symbol.
					 **
					 **  * Set the error count to three.
					 **
					 **  * Begin accepting and shifting new tokens.  No new error
					 **    processing will occur until three tokens have been
					 **    shifted successfully.
					 **
					 */
					if( yyerrcnt<0 ){
						yy_syntax_error(yymajor,yyminorunion);
					}
					yymx = yystack[yyidx].major;
					if( yymx==SQLParser_YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
						if( yyTraceFILE ){
							*yyTraceFILE << yyTracePrompt <<
							  "Discard input token " <<
								yyTokenName[yymajor] << std::endl;
						}
#endif
						yy_destructor((SQLParser_YYCODETYPE)yymajor,&yyminorunion);
						yymajor = SQLParser_YYNOCODE;
					}else{
						while(
							yyidx >= 0 &&
							yymx != SQLParser_YYERRORSYMBOL &&
							(yyact = yy_find_reduce_action(
								yystack[yyidx].stateno,
								SQLParser_YYERRORSYMBOL)) >= SQLParser_YYNSTATE
							){
							yy_pop_parser_stack();
						}
						if( yyidx < 0 || yymajor==0 ){
							yy_destructor((SQLParser_YYCODETYPE)yymajor,&yyminorunion);
							yy_parse_failed();
							yymajor = SQLParser_YYNOCODE;
						}else if( yymx!=SQLParser_YYERRORSYMBOL ){
							SQLParser_YYMINORTYPE u2;
							u2.SQLParser_YYERRSYMDT = 0;
							yy_shift(yyact,SQLParser_YYERRORSYMBOL,&u2);
						}
					}
					yyerrcnt = 3;
					yyerrorhit = 1;
#elif defined(SQLParser_YYNOERRORRECOVERY)
					/* If the SQLParser_YYNOERRORRECOVERY macro is defined, then do not attempt to
					 ** do any kind of error recovery.  Instead, simply invoke the syntax
					 ** error routine and continue going as if nothing had happened.
					 **
					 ** Applications can set this macro (for example inside %include) if
					 ** they intend to abandon the parse upon the first syntax error seen.
					 */
					yy_syntax_error(yymajor,yyminorunion);
					yy_destructor((SQLParser_YYCODETYPE)yymajor,&yyminorunion);
					yymajor = SQLParser_YYNOCODE;

#else  /* SQLParser_YYERRORSYMBOL is not defined */
					/* This is what we do if the grammar does not define ERROR:
					 **
					 **  * Report an error message, and throw away the input token.
					 **
					 **  * If the input token is $, then fail the parse.
					 **
					 ** As before, subsequent error messages are suppressed until
					 ** three input tokens have been successfully shifted.
					 */
					if( yyerrcnt<=0 ){
						yy_syntax_error(yymajor,yyminorunion);
					}
					yyerrcnt = 3;
					yy_destructor((SQLParser_YYCODETYPE)yymajor,&yyminorunion);
					if( yyendofinput ){
						yy_parse_failed();
					}
					yymajor = SQLParser_YYNOCODE;
#endif
				}
			}while( yymajor!=SQLParser_YYNOCODE && yyidx>=0 );
			return;
		}

	};

}
#endif


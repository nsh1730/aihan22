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
#ifndef PARSERTOKEN_H
#define PARSERTOKEN_H
#define TK_SEMI                             1
#define TK_EXPLAIN                          2
#define TK_ANALYZE                          3
#define TK_BEGIN                            4
#define TK_TRANSACTION                      5
#define TK_COMMIT                           6
#define TK_END                              7
#define TK_ROLLBACK                         8
#define TK_TABLE                            9
#define TK_LP                              10
#define TK_RP                              11
#define TK_CREATE                          12
#define TK_IF                              13
#define TK_NOT                             14
#define TK_EXISTS                          15
#define TK_COMMA                           16
#define TK_PRIMARY                         17
#define TK_KEY                             18
#define TK_NULL                            19
#define TK_AS                              20
#define TK_VIRTUAL                         21
#define TK_RANGE                           22
#define TK_INTERVAL                        23
#define TK_PARTITION                       24
#define TK_BY                              25
#define TK_HASH                            26
#define TK_PARTITIONS                      27
#define TK_INTEGER                         28
#define TK_SUBPARTITION                    29
#define TK_SUBPARTITIONS                   30
#define TK_EVERY                           31
#define TK_USING                           32
#define TK_TIMESERIES                      33
#define TK_WITH                            34
#define TK_EQ                              35
#define TK_FLOAT                           36
#define TK_PLUS                            37
#define TK_MINUS                           38
#define TK_ID                              39
#define TK_ABORT                           40
#define TK_ACTION                          41
#define TK_AFTER                           42
#define TK_ASC                             43
#define TK_ATTACH                          44
#define TK_BEFORE                          45
#define TK_CASCADE                         46
#define TK_CAST                            47
#define TK_COLUMNKW                        48
#define TK_CONFLICT                        49
#define TK_DATABASE                        50
#define TK_DEFERRED                        51
#define TK_DESC                            52
#define TK_DETACH                          53
#define TK_EACH                            54
#define TK_EXCLUSIVE                       55
#define TK_FAIL                            56
#define TK_FOR                             57
#define TK_IGNORE                          58
#define TK_IMMEDIATE                       59
#define TK_INITIALLY                       60
#define TK_INSTEAD                         61
#define TK_LIKE_KW                         62
#define TK_MATCH                           63
#define TK_NO                              64
#define TK_PLAN                            65
#define TK_QUERY                           66
#define TK_OF                              67
#define TK_OFFSET                          68
#define TK_PRAGMA                          69
#define TK_RAISE                           70
#define TK_RECURSIVE                       71
#define TK_RELEASE                         72
#define TK_REPLACE                         73
#define TK_RESTRICT                        74
#define TK_ROW                             75
#define TK_SAVEPOINT                       76
#define TK_TEMP                            77
#define TK_TRIGGER                         78
#define TK_VACUUM                          79
#define TK_VIEW                            80
#define TK_WITHOUT                         81
#define TK_EXTRACT                         82
#define TK_TIMESTAMPADD                    83
#define TK_TIMESTAMPDIFF                   84
#define TK_YEAR                            85
#define TK_MONTH                           86
#define TK_DAY                             87
#define TK_WEEK                            88
#define TK_HOUR                            89
#define TK_MINUTE                          90
#define TK_SECOND                          91
#define TK_MILLISECOND                     92
#define TK_GLOB                            93
#define TK_LIKE                            94
#define TK_REGEXP                          95
#define TK_TRUE                            96
#define TK_FALSE                           97
#define TK_FORCE                           98
#define TK_TIMESTAMP_TRUNC                 99
#define TK_DAY_OF_WEEK                    100
#define TK_DAY_OF_YEAR                    101
#define TK_ANY                            102
#define TK_OR                             103
#define TK_XOR                            104
#define TK_AND                            105
#define TK_IS                             106
#define TK_BETWEEN                        107
#define TK_IN                             108
#define TK_ISNULL                         109
#define TK_NOTNULL                        110
#define TK_NE                             111
#define TK_GT                             112
#define TK_LE                             113
#define TK_LT                             114
#define TK_GE                             115
#define TK_ESCAPE                         116
#define TK_BITAND                         117
#define TK_BITOR                          118
#define TK_LSHIFT                         119
#define TK_RSHIFT                         120
#define TK_STAR                           121
#define TK_SLASH                          122
#define TK_REM                            123
#define TK_CONCAT                         124
#define TK_COLLATE                        125
#define TK_BITNOT                         126
#define TK_DROP                           127
#define TK_USER                           128
#define TK_IDENTIFIED                     129
#define TK_STRING                         130
#define TK_SET                            131
#define TK_PASSWORD                       132
#define TK_GRANT                          133
#define TK_ALL                            134
#define TK_ON                             135
#define TK_TO                             136
#define TK_SELECT                         137
#define TK_REVOKE                         138
#define TK_FROM                           139
#define TK_INDEX                          140
#define TK_DOT                            141
#define TK_ALTER                          142
#define TK_ADD                            143
#define TK_UNION                          144
#define TK_EXCEPT                         145
#define TK_INTERSECT                      146
#define TK_VALUES                         147
#define TK_HINT_START                     148
#define TK_HINT_END                       149
#define TK_DISTINCT                       150
#define TK_JOIN                           151
#define TK_INNER                          152
#define TK_CROSS                          153
#define TK_LEFT                           154
#define TK_OUTER                          155
#define TK_RIGHT                          156
#define TK_FULL                           157
#define TK_NATURAL                        158
#define TK_ORDER                          159
#define TK_GROUP                          160
#define TK_HAVING                         161
#define TK_LIMIT                          162
#define TK_WHERE                          163
#define TK_DELETE                         164
#define TK_UPDATE                         165
#define TK_INTO                           166
#define TK_INSERT                         167
#define TK_BLOB                           168
#define TK_VARIABLE                       169
#define TK_OVER                           170
#define TK_CASE                           171
#define TK_WHEN                           172
#define TK_THEN                           173
#define TK_ELSE                           174
#define TK_TO_TEXT                        175
#define TK_TO_BLOB                        176
#define TK_TO_NUMERIC                     177
#define TK_TO_INT                         178
#define TK_TO_REAL                        179
#define TK_ISNOT                          180
#define TK_END_OF_FILE                    181
#define TK_ILLEGAL                        182
#define TK_SPACE                          183
#define TK_UNCLOSED_STRING                184
#define TK_FUNC                           185
#define TK_COLUMN                         186
#define TK_AGG_FUNCTION                   187
#define TK_AGG_COLUMN                     188
#define TK_CONST_FUNC                     189
#define TK_UMINUS                         190
#define TK_UPLUS                          191
#define TK_GISFUNC                        192
#endif

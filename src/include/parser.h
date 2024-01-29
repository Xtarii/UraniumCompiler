#ifndef PARSER_H
#define PARSER_H
#include "token.h"
#include "AST.h"
#include "lexer.h"



/// @brief PARSER Structure
typedef struct PARSER_STRUCT{
    lexer_s* lexer;
    token_s* currentToken;
    token_s* previusToken;
} parser_s;
parser_s* init_parser(lexer_s* lexer);


int parser_acceptString(parser_s* parser, const char* value);
void parser_expect(parser_s* parser, int tokenType);
void parser_expectString(parser_s* parser, const char* value);

ast_s* parser_parse(parser_s* parser);

/// @brief Parse Statement
/// @param parser PARSER
/// @return AST
ast_s* parser_parseStatement(parser_s* parser);
/// @brief Parse Statements
/// @param parser PARSER
/// @return AST
ast_s* parser_parseStatements(parser_s* parser);

/// @brief Parse Expression
/// @param parser PARSER
/// @return AST
ast_s* parser_parseExpression(parser_s* parser);

/// @brief Parse Factor
/// @param parser PARSER
/// @return AST
ast_s* parser_parseFactor(parser_s* parser);

/// @brief Parse Term
/// @param parser PARSER
/// @return AST
ast_s* parser_parseTerm(parser_s* parser);


/// @brief Parse Function Call
/// @param parser PARSER
/// @return AST
ast_s* parser_parseFunctionCall(parser_s* parser);

/// @brief Parse Variable
/// @param parser PARSER
/// @return AST
ast_s* parser_parseVariable(parser_s* parser);
/// @brief Parse Variable Definition
/// @param parser PARSER
/// @return AST
ast_s* parser_parseVariableDefinition(parser_s* parser);

/// @brief Parse String
/// @param parser PARSER
/// @return AST
ast_s* parser_parseString(parser_s* parser);

/// @brief Parse Identifier
/// @param parser PARSER
/// @return AST
ast_s* parser_parseIdentifier(parser_s* parser);


#endif

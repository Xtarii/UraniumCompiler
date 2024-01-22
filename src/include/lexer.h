#ifndef LEXER_H
#define LEXER_H
#include "token.h"



/// @brief LEXER Struct
typedef struct LEXER_STURCT{
    char c;
    unsigned int i;
    char* contents;
} lexer_s;

/// @brief Creates Lexer
/// @param contents Content
/// @return LEXER
lexer_s* init_lexer(char* contents);

void lexer_next(lexer_s* lexer);
void lexer_skipWhiteSpace(lexer_s* lexer);


/// @brief Get Next Token
/// @param lexer LEXER
/// @return Token
token_s* lexer_nextToken(lexer_s* lexer);
/// @brief Get Token String Value
/// @param lexer LEXER
/// @return String
token_s* lexer_getTokenString(lexer_s* lexer);
/// @brief Get Token Identifier Value
/// @param lexer LEXER
/// @return Identifier
token_s* lexer_getTokenNumber(lexer_s* lexer);
/// @brief Gets Next Token with Token
/// @param lexer LEXER
/// @return Token
token_s* lexer_nextWithToken(lexer_s* lexer, token_s* token);


/// @brief Get Current Character as String
/// @param lexer LEXER
/// @return String
char* lexer_getCurrentCharAsString(lexer_s* lexer);

#endif

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/lexer.h"


lexer_s* init_lexer(char* contents){
    lexer_s* lexer = calloc(1, sizeof(struct LEXER_STURCT));
    
    // Config
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = lexer->contents[lexer->i];

    return lexer;
}



void lexer_next(lexer_s* lexer){
    if(lexer->c != '\0' && lexer->i < strlen(lexer->contents)){
        lexer->i += 1;
        lexer->c = lexer->contents[lexer->i];
    }
}
void lexer_skipWhiteSpace(lexer_s* lexer){
    while(lexer->c == ' ' || lexer->c == 10){
        lexer_next(lexer);
    }
}



char* lexer_getCurrentCharAsString(lexer_s* lexer){
    char* string = calloc(2, sizeof(char)); // Creates Dynamic String
    string[0] = lexer->c;
    string[1] = '\0';
    
    return string; // Return String
}


/// @brief Skips White Space
/// @param lexer LEXER
/// @param token TOKEN
/// @return token
token_s* lexer_nextWithToken(lexer_s* lexer, token_s* token){
    lexer_next(lexer);
    return token;
}

/// @brief Reads String
/// @param lexer LEXER
/// @return String
token_s* lexer_getTokenString(lexer_s* lexer){
    lexer_next(lexer);
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    // Collects string
    while(lexer->c != '"'){
        char* string = lexer_getCurrentCharAsString(lexer);
        value = realloc(value, (strlen(value) + strlen(string) + 1) * sizeof(char));
        strcat(value, string);
        lexer_next(lexer); // Next Token
    }
    lexer_next(lexer);
    return init_token(STRING, value);
}
/// @brief Reads Number
/// @param lexer LEXER
/// @return Number
token_s* lexer_getTokenIdentifier(lexer_s* lexer){
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    // Collects string
    while(isalnum(lexer->c)){
        char* string = lexer_getCurrentCharAsString(lexer);
        value = realloc(value, (strlen(value) + strlen(string) + 1) * sizeof(char));
        strcat(value, string);
        lexer_next(lexer); // Next Token
    }
    return init_token(IDENTIFIER, value);
}



/// @brief Next Token
/// @param lexer LEXER
/// @return Token
token_s* lexer_nextToken(lexer_s* lexer){
    while(lexer->c != '\0' && lexer->i < strlen(lexer->contents)){
        if(lexer->c == ' ' || lexer->c == 10)
            lexer_skipWhiteSpace(lexer);

        

        // Number Token
        if(isalnum(lexer->c))
            return lexer_getTokenIdentifier(lexer);
        // String Token
        if(lexer->c == '"')
            return lexer_getTokenString(lexer);

        // Token Type Lexing
        switch(lexer->c){
            /* OPERATOR TOKEN */
            case '=': return lexer_nextWithToken(lexer, init_token(OPERATOR, lexer_getCurrentCharAsString(lexer)));
            case '+': return lexer_nextWithToken(lexer, init_token(OPERATOR, lexer_getCurrentCharAsString(lexer)));

            case '(': return lexer_nextWithToken(lexer, init_token(OPERATOR, lexer_getCurrentCharAsString(lexer)));
            case ')': return lexer_nextWithToken(lexer, init_token(OPERATOR, lexer_getCurrentCharAsString(lexer)));

            
            /* ENDLINE TOKEN */
            case ';': return lexer_nextWithToken(lexer, init_token(SEMICOLON, lexer_getCurrentCharAsString(lexer)));
        }
    }

    return init_token(ENDOFFILE, "\0");
}

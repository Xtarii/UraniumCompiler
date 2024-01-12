#include <string.h>
#include <ctype.h>

#include <stdio.h>



/// @brief Token Types Enum
enum TokenTypes{
    // Indetifiers
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    
    // Variable Types
    NUMBER,
    
    NEWLINE // New Line
};

/// @brief Token Object
struct Token{
    enum TokenTypes type;
    char value[256];
};





/// @brief Checks if ```String``` is Keyword Type
/// @param str String
/// @return Boolean Status
int isKeyword(char *str){
    if(strcmp(str, "int") == 0){
        return 1;
    }

    return 0;
}

int isOperator(char *str){
    if(strcmp(str, "=") == 0){
        return 1;
    }else if(strcmp(str, "+") == 0){
        return 1;
    }

    return 0;
}


/// @brief Tokenizes String to Readeble format
/// @param code String for Tokenizing
void Tokenize(char code[], struct Token* tokens){
    int position = 0;
    char *line = strtok(code, ";"); // Spliting at split-char

    while(line != NULL){
        // Getting Token
        char *token = strtok(line, " ");

        while(token != NULL){
            // Creates Token
            struct Token _token;


            // Key Word Identifiers
            if(isKeyword(token)){
                _token.type = KEYWORD;
            
            // Digit Token
            }else if(isdigit(token[0])){
                _token.type = NUMBER;
            
            // Operator Token
            }else if(isOperator(token)){
                _token.type = OPERATOR;
            
            // Identifier Token
            }else{
                _token.type = IDENTIFIER;
            }


            strcpy(_token.value, token); // Applies Token to Token Value
            tokens[position++] = _token; // Adds Token to Token List
            token = strtok(NULL, " ");   // Next Word
        }
        line = strtok(NULL, ";"); // Next Line
    }
}

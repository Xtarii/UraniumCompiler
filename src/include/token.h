#ifndef TOKEN_H
#define TOKEN_H



/// @brief TOKEN Struct
typedef struct TOKEN_STRUCT{
    enum{
        // Indetifiers
        KEYWORD,
        IDENTIFIER,
        OPERATOR,
        
        // Variable Types
        NUMBER,
        STRING,
        

        SEMICOLON, // Semicolon
        ENDLINE,   // End of Line
    } type;
    char* value;
} token_s;
token_s* init_token(int type, char* value);

#endif
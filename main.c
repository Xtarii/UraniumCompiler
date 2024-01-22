// #include "formater/headers/token.h"
// #include "formater/tokenizer.c"
// #include "formater/parser/astnode.c"


#include <stdio.h>
#include "src/include/lexer.h"



/// @brief Uranium Compiler Executer
/// @param argc Argument Count
/// @param argv Argument Values
/// @return Execution Status
int main(int argc, char const *argv[])
{
    char code[] = "int myVar = 5; int myOtherVar = 10;"; // Code Test


    // Lexer
    lexer_s* lexer = init_lexer(
        "int myVar = 5;\n"
        "int myOtherVar = 5;\n"
    );
    token_s* token = (void*)0;

    
    // Lexing Tokens
    while((token == lexer_nextToken(lexer)) != (void*)0){
        printf("TOKEN(%d : %s)\n", token->type, token->value);
    }




    // // Setup
    // //GenerateDynamicList(code);


    // // Compiler
    // Tokenize(code); // Tokenizing code String to Token List
    // parse();        // Parsing Token List to AST


    return 0;
}

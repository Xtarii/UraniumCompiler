#include <stdio.h>
#include "src/include/lexer.h"
#include "src/include/parser.h"



/// @brief Uranium Compiler Executer
/// @param argc Argument Count
/// @param argv Argument Values
/// @return Execution Status
int main(int argc, char const *argv[])
{
    // Lexer
    lexer_s* lexer = init_lexer(
        "string name = \"Alvin Hansen\";"
        "string t = \"Hello World\";"

        "myFunc();"
    );
    
    // Parser
    parser_s* parser = init_parser(lexer);
    ast_s* tree = parser_parse(parser);


    printf("%d\n", tree->type);
    printf("%d\n", tree->compound_size);


    return 0;
}

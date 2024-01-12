#include "formater/tokenizer.c"



/// @brief Uranium Compiler Executer
/// @param argc Argument Count
/// @param argv Argument Values
/// @return Execution Status
int main(int argc, char const *argv[])
{
    struct Token tokens[256];
    char code[] = "int myVar = 4 + 5;"; // Code Test

    // Tokenizing code String to Token List
    Tokenize(code, tokens);


    return 0;
}
#ifndef AST_H
#define AST_H
#include <ctype.h>
#include <stdlib.h>



/// @brief AST Structure
typedef struct AST_STRUCT{
    // AST Node Type
    enum{
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,

        AST_STRING,

        AST_FUNCTION_CALL,

        AST_COMPOUND,
    } type;

    /* AST Type VARIABLE_DEFINITION */
    char* variable_definition_name;
    struct AST_STRUCT* variable_definition_value;

    /* AST Type VARIABLE */
    char* variable_name;


    /* AST Type STRING */
    char* string_value;


    /* AST Type AST_FUNCTION_CALL */
    char* function_call_name;
    struct AST_STRUCT** function_call_arguments;
    size_t function_call_arguments_size;


    /* AST Type COMPOUND */
    struct AST_STRUCT** compound_value;
    size_t compound_size;
} ast_s;
ast_s* init_ast(int type);

#endif

#include <stdlib.h>
#include "include/AST.h"



ast_s* init_ast(int type){
    ast_s* ast = calloc(1, sizeof(struct AST_STRUCT));

    // Config
    ast->type = type;

    // AST VARIABLE_DEFINITION
    ast->variable_definition_name = (void*)0;
    ast->variable_definition_value = (void*)0;

    // AST VARIABLE
    ast->variable_name = (void*)0;

    // AST STRING
    ast->string_value = (void*)0;

    // AST AST_FUNCTION_CALL
    ast->function_call_name = (void*)0;
    ast->function_call_arguments = (void*)0;
    ast->function_call_arguments_size = 0;

    // AST COMPOUND
    ast->compound_value = (void*)0;
    ast->compound_size = 0;

    return ast;
}

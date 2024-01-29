#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/parser.h"



parser_s* init_parser(lexer_s* lexer){
    parser_s* parser = calloc(1, sizeof(struct PARSER_STRUCT));

    // Config
    parser->lexer = lexer;
    parser->currentToken = lexer_nextToken(lexer);
    parser->previusToken = parser->currentToken;

    return parser;
}
ast_s* parser_parse(parser_s* parser){
    return parser_parseStatements(parser);
}



/* Parse: Accept */

int parser_acceptString(parser_s* parser, const char* value){
    if(strcmp(parser->currentToken->value, value) == 0){
        return 1;
    }else{
        return 0;
    }
}

/* Parse: Expect */

void parser_expect(parser_s* parser, int tokenType){
    if(parser->currentToken->type == tokenType){
        parser->previusToken = parser->currentToken;
        parser->currentToken = lexer_nextToken(parser->lexer);
    
    // Unexpected Token Error
    }else{
        printf(
            "[ Error ] -> Unexpected token \"%s\" of type \"%d\"",
            parser->currentToken->value, parser->currentToken->type);


        // Exit Program
        exit(1);
    }
}
void parser_expectString(parser_s* parser, const char* value){
    if(parser_acceptString(parser, value)){
        parser->currentToken = lexer_nextToken(parser->lexer);
    
    // Unexpected Token Error
    }else{
        printf(
            "[ Error ] -> Unexpected token \"%s\" of type \"%d\"",
            parser->currentToken->value, parser->currentToken->type);


        // Exit Program
        exit(1);
    }
}



/* Parse: Statement(s) */

ast_s* parser_parseStatement(parser_s* parser){
    switch(parser->currentToken->type){
        case IDENTIFIER: return parser_parseIdentifier(parser);
    }
}
ast_s* parser_parseStatements(parser_s* parser){
    ast_s* compound = init_ast(AST_COMPOUND);
    compound->compound_size = 0;
    compound->compound_value = calloc(1, sizeof(struct AST_STRUCT*));

    // First Statement
    ast_s* statement = parser_parseStatement(parser);
    compound->compound_value[0] = statement;

    // Other Statements
    while(parser->currentToken->type == SEMICOLON){
        // Expect SEMICOLON
        parser_expect(parser, SEMICOLON);

        // Parse statement
        ast_s* statement = parser_parseStatement(parser);
        if(statement){
            compound->compound_size++;
            compound->compound_value = realloc(compound->compound_value, compound->compound_size * sizeof(struct AST_STRUCT*));
            compound->compound_value[compound->compound_size-1] = statement;
        }
    }

    return compound;
}


ast_s* parser_parseExpression(parser_s* parser){
    switch(parser->currentToken->type){
        case STRING: return parser_parseString(parser);
    }
}

ast_s* parser_parseFactor(parser_s* parser){}

ast_s* parser_parseTerm(parser_s* parser){}

ast_s* parser_parseString(parser_s* parser){
    ast_s* string = init_ast(AST_STRING);
    string->string_value = parser->currentToken->value;

    parser_expect(parser, STRING);

    return string;
}

ast_s* parser_parseFunctionCall(parser_s* parser){
    ast_s* functionCall = init_ast(AST_FUNCTION_CALL);
    parser_expectString(parser, "(");

    // Arguments
    functionCall->function_call_name = parser->previusToken->value;
    functionCall->function_call_arguments = calloc(1, sizeof(struct AST_STRUCT*));
    ast_s* expression = parser_parseExpression(parser);
    functionCall->function_call_arguments[0] = expression;

    // Other Arguments
    while(parser_acceptString(parser, ",")){
        // Expect SEMICOLON
        parser_expectString(parser, ",");


        // Parse statement
        ast_s* expression = parser_parseExpression(parser);
        functionCall->function_call_arguments_size++;
        functionCall->function_call_arguments = realloc(
            functionCall->function_call_arguments,
            functionCall->function_call_arguments_size * sizeof(struct AST_STRUCT*));

        functionCall->function_call_arguments[functionCall->function_call_arguments_size-1] = expression;
    }
    parser_expectString(parser, ")");
    return functionCall;
}



ast_s* parser_parseVariable(parser_s* parser){
    char* tokenValue = parser->currentToken->value;
    parser_expect(parser, IDENTIFIER); // Variable Name or Function

    // Function Call
    if(parser_acceptString(parser, "("))
        return parser_parseFunctionCall(parser);

    
    // Variable
    ast_s* variable = init_ast(AST_VARIABLE);
    variable->variable_name = tokenValue;

    return variable;
}
ast_s* parser_parseVariableDefinition(parser_s* parser){
    parser_expect(parser, IDENTIFIER); // Expect Variable Identifier
    char* variableName = parser->currentToken->value;
    
    parser_expect(parser, IDENTIFIER); // Name
    parser_expectString(parser, "=");   // Equal Sign

    ast_s* variableValue = parser_parseExpression(parser);
    ast_s* variableDefinition = init_ast(AST_VARIABLE_DEFINITION);

    variableDefinition->variable_definition_name = variableName;
    variableDefinition->variable_definition_value = variableValue;

    return variableDefinition;
}


ast_s* parser_parseIdentifier(parser_s* parser){
    // Integer
    if(parser_acceptString(parser, "int")){
        return parser_parseVariableDefinition(parser);
    
    // String
    }else if(parser_acceptString(parser, "string")){
        return parser_parseVariableDefinition(parser);
    
    // Return Variable
    }else{
        return parser_parseVariable(parser);
    }
}

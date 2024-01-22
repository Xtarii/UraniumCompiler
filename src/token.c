#include <stdlib.h>
#include "include/token.h"


token_s* init_token(int type, char* value){
    token_s* token = calloc(1, sizeof(struct TOKEN_STRUCT));

    // Config
    token->type = type;
    token->value = value;

    return token;
}
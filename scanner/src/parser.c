#include "include/parser.h"

void parser_parse(CompilerContext *ctx) {
    Token t;
    do  {
        t = ctx->lexic_read_token(ctx);
        if (t != null) {
            token_print(t);
        }
    } while (t != null);
}

#include "include/parser.h"
#include "include/lexic.h"
#include "include/token.h"

// Entrypoint
// Função que chama repetidamente o analizado léxico para ler o próximo token
void parser_parse(CompilerContext *ctx) {
    Token t;
    do  {
        t = lexic_read_token(ctx);
        if (t.type == TokenNULL)
            break;
        if (t.type != TokenEOF) {
            token_print(&t);
            free_token(&t);
        }
    } while (t.type != TokenEOF);
}

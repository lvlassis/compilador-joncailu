#include "include/lexic.h"

// Função que retorna o próximo token, consumindo parte da string
Token lexic_read_token(CompilerContext* ctx) {
    int pos_inicial = ctx->current_pos;
    Token t = {TokenEOF, ""};
    return t;
}

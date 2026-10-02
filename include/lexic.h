#ifndef LEXIC_H
#define LEXIC_H

#include "token.h"
#include "compiler.h"

Token lexic_read_token(CompilerContext* ctx);
// Sempre que chamada, calcula e retorna o próximo token do código fonte.

Token lexic_peek_token(CompilerContext* ctx);
// Função que retorna qual o próximo token, sem efetivamente consumir ele.

int get_end_token(CompilerContext*);
// Função que percorre o código fonte até encontrar o final do token atual, retornando a posição do cursor final

#endif // LEXIC_H

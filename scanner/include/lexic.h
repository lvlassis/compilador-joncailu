#ifndef LEXIC_H
#define LEXIC_H

Token lexic_read_token(CompilerContext* ctx);
// Sempre que chamada, calcula e retorna o próximo token do código fonte.

Token lexic_peek_token(CompilerContext* ctx);
// Função que retorna qual o próximo token, sem efetivamente consumir ele.

#endif // LEXIC_H

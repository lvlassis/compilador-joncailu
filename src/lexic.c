#include "include/lexic.h"

// Função que retorna o próximo token, consumindo parte da string
Token lexic_read_token(CompilerContext* ctx) {
    int cursor = ctx->current_pos;          // Posição do cursor na string
    char value = ctx->source_code[cursor]   // Valor do cursor
    
    // Implementar lógica de percorrer a string do código fonte para 
    // identificar onde inicia e termina o próximo lexema
    
    // Implementar lógica de classificar o lexema selecionado 
    // gerando um token.
    
    // Mover o ctx->current_pos; para o final do lexema identificado

    // (MOCK) Retorna sempre token EOF
    Token t = {TokenEOF, ""};
    return t;
}

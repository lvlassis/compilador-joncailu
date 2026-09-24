#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/lexic.h"
#include "include/token.h"
#include "include/automaton.h"

// Função que retorna o próximo token, consumindo parte da string
Token lexic_read_token(CompilerContext* ctx) {
    int cursor = ctx->current_pos;          // Posição do cursor na string
    int auxCursor = cursor;
    char value = ctx->source_code[cursor];   // Valor do cursor
    StateType state = Start;                // Estado do autômato
    TokenType tokenType = TokenNULL;

    for (int i = 0; tokenType == TokenNULL || tokenType == TokenIgn; i++) 
    {
        auxCursor = cursor + i;
        value = ctx->source_code[auxCursor];

        tokenType = handle_state_transition(&state, value);
        if (tokenType == TokenIgn) i++;
        printf("NewState: %d\n", state);
        printf("TokenType: %d\n\n", tokenType);
        if (state == Error)
        {
            printf("Error!");
            break;
        }
    }

    char *charCopy = (char *)malloc((auxCursor + 1) * sizeof(char));
    
    if (charCopy == NULL) {
        printf("Erro de alocação de memória.\n");
    }

    strncpy(charCopy, ctx->source_code, auxCursor);
    charCopy[auxCursor] = '\0';
    
    ctx->source_code += auxCursor;
    Token t = {tokenType, charCopy};
    return t;
}

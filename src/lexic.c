#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/lexic.h"
#include "include/compiler.h"
#include "include/token.h"
#include "include/automaton.h"

// Função que retorna o próximo token, consumindo parte da string
Token lexic_read_token(CompilerContext* ctx) {
    int cursor_final_token = get_end_token(ctx);

    char *charCopy = (char *)malloc((auxCursor + 1) * sizeof(char));
    
    if (charCopy == NULL) {
        printf("Erro de alocação de memória.\n");
        return (Token) {TokenNULL, ""};
    }

    strncpy(charCopy, ctx->source_code, auxCursor);
    charCopy[auxCursor] = '\0';
    
    ctx->source_code += auxCursor;
    if (tokenType == TokenID)
    {
        tokenType = lookup_token(charCopy);
    }
    Token t = {tokenType, charCopy};
    return t;
}


typedef enum {
    StartSBD,
    AlphaNum,
    NumericSBD,
    CommentSBD,
    GreatherThanSBD,
    LessThanSBD,
    EqualSBD,
    DifferentSBD,
    BinaryOperatorSBD,
} StateBorderDetector;

int get_end_token(CompilerContext* ctx) {
    // Percorre o código fonte até encontrar o final do token atual, retornando a posição do cursor final
    // Sugestão de otimização: utilizar regex para identificar o final do token atual, ao invés de percorrer o código fonte caractere por caractere.
    int cursor_o = ctx->lexic_cursor;
    int cursor_i = cursor_o;
    StateType state = Start;                // Estado do autômato

    // Pega o valor do character atual do cursor
    char value = ctx->source_code[cursor_i];
                                               
    // Verifica token de um caractere (, ), {, }, ;, etc.)
    switch (value) { 
        case '{':
        case '}':
        case ';':
        case '(':
        case ')':
        case ',':
        case '\n':
            return cursor_i + 1;
    }

    // Stripa espaços em branco
    while (isspace(value)) {
        cursor_i++;
        value = ctx->source_code[cursor_i];
    }
    
    // Calcula o estado inicial
    if (isalpha(value) || value == '_') {
        state = AlphaNum;
    } else if (isdigit(value)) {
        state = Numeric;
    } else if (value == '/') {
        state = Comment;
    } else if (value == '>') {
        state = GreatherThan;
    } else if (value == '<') {
        state = LessThan;
    } else if (value == '=') {
        state = Equal;
    } else if (value == '!') {
        state = Different;
    } else if (isBinaryOperator(value)) {
        state = BinaryOperator;
    } else {
        return cursor_i + 1; // Retorna a posição do cursor final
    }

    // Percorre o código fonte até encontrar uma transição de estado que indique o final do token atual
}


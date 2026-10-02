#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/lexic.h"
#include "include/compiler.h"
#include "include/token.h"
#include "include/automaton.h"

Token lexic_read_token(CompilerContext* ctx) {
// Função que retorna o próximo token, consumindo parte da string
    int cursor_final_token = get_end_token(ctx);

    // Calcula o tamanho do token atual
    int lenght = cursor_final_token - ctx->lexic_cursor + 1;

    // Aloca e copia o token atual para uma nova string
    char *charCopy = (char *)malloc((lenght + 1) * sizeof(char));
    if (charCopy == NULL) {
        printf("Erro de alocação de memória.\n");
        return (Token) {TokenNULL, ""};
    }
    strncpy(charCopy, ctx->source_code, lenght);
    charCopy[lenght] = '\0';
    
    // Atualiza o cursor do contexto para a posição do próximo token
    ctx->lexic_cursor = cursor_final_token + 1;

    // Classifica o token atual
    TokenType tokenType = lookup_token(charCopy);
    Token t = {tokenType, charCopy};
    return t;
}


typedef enum {
    AlphaNumSBD,
    NumericSBD,
    CommentSBD,
    GreatherThanSBD,
    LessThanSBD,
    EqualSBD,
    DifferentSBD,
    BinaryOperatorSBD,
} StateBorderDetector;
// Estados do autômato para detectar o final do token atual

int get_end_token(CompilerContext* ctx) {
    // Percorre o código fonte até encontrar o final do token atual, retornando a posição do cursor final
    // Sugestão de otimização: utilizar regex para identificar o final do token atual, ao invés de percorrer o código fonte caractere por caractere.
    int cursor_o = ctx->lexic_cursor;
    int cursor_i = cursor_o;
    StateBorderDetector state;                // Estado do autômato

    // Pega o valor do character atual do cursor
    char value = ctx->source_code[cursor_i];
                                               
    // Stripa espaços em branco
    while (isspace(value) && value != '\n') {
        cursor_i++;
        value = ctx->source_code[cursor_i];
    }
    cursor_o = cursor_i; // Atualiza o cursor de saída para a posição do primeiro caractere não branco
    
    // Verifica token de um caractere (, ), {, }, ;, etc.)
    switch (value) { 
        case '{':
        case '}':
        case ';':
        case '(':
        case ')':
        case ',':
        case '\n':
            return cursor_i;
    }

    // Calcula o estado inicial
    if (isalpha(value) || value == '_') {
        state = AlphaNumSBD;
    } else if (isdigit(value)) {
        state = NumericSBD;
    } else if (value == '/') {
        state = CommentSBD;
    } else if (value == '>') {
        state = GreatherThanSBD;
    } else if (value == '<') {
        state = LessThanSBD;
    } else if (value == '=') {
        state = EqualSBD;
    } else if (value == '!') {
        state = DifferentSBD;
    } else {
        return cursor_i - 1; // Retorna a posição do cursor final
    }

    // Percorre o código fonte até encontrar uma transição de estado que indique o final do token atual
    for (int i = 0; value != '\0'; i++) {
        cursor_i = cursor_o + i;
        value = ctx->source_code[cursor_i];

        switch (state) {
            case AlphaNumSBD:
                if (!isalnum(value) && value != '_') {
                    return cursor_i - 1; // Retorna a posição antes da borda
                }
                break;
            case NumericSBD:
                if (!isdigit(value)) {
                    return cursor_i; // Retorna a posição antes da borda
                }
                break;
            case CommentSBD:
                if (value == '\n') {
                    return cursor_i; // Retorna a posição antes da borda
                }
                break;
            case GreatherThanSBD:
                if (value != '=') {
                    return cursor_i; // Retorna a posição antes da borda
                }
                break;
            case LessThanSBD:
                if (value != '=') {
                    return cursor_i; // Retorna a posição antes da borda
                }
                break;
            case EqualSBD:
                if (value != '=') {
                    return cursor_i; // Retorna a posição antes da borda
                }
                break;
            case DifferentSBD:
                if (value != '=') {
                    return cursor_i; // Retorna a posição antes da borda
                }
                break;
            }
        if (value == '\0') {
            return cursor_i; // Retorna a posição antes da borda
        }
    }
    return cursor_i; 
}


#ifndef COMPILER_H
#define COMPILER_H

// Contexto do Compilador
// Local para colocar variáveis globais para os componentes conversarem entre sí
typedef struct {
    char *source_code; // Ponteiro do código fonte a ser compilado (str)
    int lexic_cursor;        // Posição que estamos lendo o source code
} CompilerContext;

#endif // COMPILER_H

#ifndef COMPILER_H
#define COMPILER_H

// Contexto do Compilador
// Local para colocar variáveis globais para os componentes conversarem entre sí
typedef struct {
    char *source_code; // Código fonte a ser compilado (str)
    int current_pos;
} CompilerContext;

#endif // COMPILER_H

#include <stdio.h>
#include "include/parser.h"

// Contexto do Compilador
// Local para colocar variáveis globais para os componentes conversarem entre sí
typedef struct {
    char *source_code; // Código fonte a ser compilado (str)
} CompilerContext;


int main() {
    // Inicializa o contexto do compilador
    CompilerContext context;
    
    // examples/quadradinho.jkl
    context.source_code = "programa quadradinho;\n\ninicio {\nrepetir {\nandar();\n andar();\n direita();\n }\n }\n ";

    // Executa a compilação!
    parser_parse(&ctx);

    return 0;
}

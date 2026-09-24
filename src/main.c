#include <stdio.h>
#include "include/parser.h"
#include "include/compiler.h"


int main() {
    // Inicializa o contexto do compilador
    // com examples/quadradinho.jkl
    CompilerContext ctx;
    ctx.current_pos = 0;
    ctx.source_code = "programa quadradinho;\n\ninicio {\nrepetir {\nandar();\n andar();\n direita();\n }\n }\n ";

    // Executa a compilação!
    parser_parse(&ctx);

    return 0;
}

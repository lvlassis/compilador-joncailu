#include <stdio.h>
#include "include/compiler.h"
#include "include/lexic.h"


int main() {
    int gabarito[] = {7, 19, 20, 21, 22, 28, 30, 31, 32, 33, 40, 42, 43, 48, 49, 50, 51, 52, 58, 59, 60, 61, 62, 70, 71, 72, 73, 74, 76, 77, 79, 80};
    printf("[Test] get_end_token...\n");

    // Inicializa o contexto do compilador
    // com examples/quadradinho.jkl
    CompilerContext ctx;
    ctx.lexic_cursor = 0;
    ctx.source_code = "programa quadradinho;\n\ninicio {{}\nrepetir {\nandar();\n andar();\n direita();\n }\n }\n\0";

    int gabarito_len = sizeof(gabarito) / sizeof(gabarito[0]);
    int i = 0;
    int passed = 1;

    char value = ctx.source_code[ctx.lexic_cursor];
    while (value != '\0') {
        int end = get_end_token(&ctx);
        char value_end = ctx.source_code[end];
        char label[4] = {value_end, '\0'};
        if (value_end == '\n') label[0] = '\\', label[1] = 'n', label[2] = '\0';

        if (i >= gabarito_len) {
            printf("EXTRA [%d] got %d %s\n", i, end, label);
            passed = 0;
        } else if (end == gabarito[i]) {
            printf("OK    [%d] %d %s\n", i, end, label);
        } else {
            printf("FAIL  [%d] got %d %s, esperado %d\n", i, end, label, gabarito[i]);
            passed = 0;
        }
        fflush(stdout);

        i++;
        ctx.lexic_cursor = end + 1;
        value = ctx.source_code[ctx.lexic_cursor];
    }

    if (i < gabarito_len) {
        printf("FAIL: esperado %d tokens, encontrou %d\n", gabarito_len, i);
        passed = 0;
    }

    return 0;
    return passed ? 0 : 1;

}

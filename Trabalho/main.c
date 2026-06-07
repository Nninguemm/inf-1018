#include <stdio.h>
#include "cria_func.h"

int mult(int x, int y) { return x * y; }

/* Caso crítico: FIX no param[0], PARAM no param[1]
   A nova função recebe 1 arg (em %rdi).
   PARAM_f será chamada com i=1, cont_param=0.
   Seu código gera: 48 89 f7 = mov %rsi, %rdi
   MAS o argumento da nova função está em %rdi, não %rsi!
   %rsi nesse momento tem lixo. */
void teste_fix_param() {
    printf("=== FIX(7) + PARAM: esperado mult(7, x) ===\n");
    typedef int (*fp)(int);
    DescParam p[2];
    unsigned char codigo[500];
    p[0].tipo_val = INT_PAR; p[0].orig_val = FIX;   p[0].valor.v_int = 7;
    p[1].tipo_val = INT_PAR; p[1].orig_val = PARAM;
    cria_func(mult, p, 2, codigo);
    fp f = (fp)codigo;
    for (int i = 1; i <= 5; i++)
        printf("f(%d) = %d  (esperado: %d)\n", i, f(i), 7*i);
}

/* Caso: PARAM + FIX + PARAM com 3 args
   Nova função recebe 2 args: em %rdi e %rsi.
   param[0]=PARAM: cont_param=0, i=0 → não move (ok, %rdi já está certo)
   param[1]=FIX(10): escreve 10 em %esi → SOBRESCREVE o 2º arg da nova função!
   param[2]=PARAM: cont_param=1, i=2 → gera mov %rsi,%rdx
                   mas %rsi agora tem 10, não o 2º argumento original! */
int soma3(int x, int y, int z) { return x + y + z; }

void teste_param_fix_param() {
    printf("\n=== PARAM + FIX(10) + PARAM: esperado soma3(x, 10, y) ===\n");
    typedef int (*fp)(int, int);
    DescParam p[3];
    unsigned char codigo[500];
    p[0].tipo_val = INT_PAR; p[0].orig_val = PARAM;
    p[1].tipo_val = INT_PAR; p[1].orig_val = FIX;   p[1].valor.v_int = 10;
    p[2].tipo_val = INT_PAR; p[2].orig_val = PARAM;
    cria_func(soma3, p, 3, codigo);
    fp f = (fp)codigo;
    /* f(3, 5) deveria chamar soma3(3, 10, 5) = 18 */
    printf("f(3,5) = %d  (esperado: 18)\n", f(3, 5));
    printf("f(1,2) = %d  (esperado: 13)\n", f(1, 2));
}

int main(void) {
    teste_fix_param();
    teste_param_fix_param();
    return 0;
}
#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr)(int x, int y);

int mult(int x, int y) {
    return x * y;
}

int main() {
    unsigned char codigo[500];

    DescParam params[2];

    // x = PARAM (vem da função gerada)
    params[0].tipo_val = INT_PAR;
    params[0].orig_val = PARAM;

    // y = FIX (sempre 10)
    params[1].tipo_val = INT_PAR;
    params[1].orig_val = FIX;
    params[1].valor.v_int = 10;

    cria_func(mult, params, 2, codigo);

    func_ptr f = (func_ptr) codigo;

    for (int i = 1; i <= 10; i++) {
        printf("%d x 10 = %d\n", i, f(i, 0));
    }

    return 0;
}
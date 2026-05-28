#include <stdio.h>
#include <math.h>


float foo(double a, float b);
float foo1(float a, float b);
double foo2(float a, float b);
double foo3(double* a, int n);

int main() {
    double a = 10.5;
    float b = 2.5;

    float resultado = foo(a, b);

    printf("a = %.2lf\n", a);
    printf("b = %.2f\n", b);
    printf("Resultado = %.2f\n", resultado);
//---------------------------------------------
    float a1 = 1.0f;
    float b1 = 2.0f;

    float r1 = foo1(a1, b1);

    printf("=== foo1 ===\n");
    printf("a = %.2f\n", a1);
    printf("b = %.2f\n", b1);
    printf("Resultado = %.6f\n\n", r1);

    // =========================
    float a2 = 1.0f;
    float b2 = 0.5f;

    double r2 = foo2(a2, b2);

    printf("=== foo2 ===\n");
    printf("a = %.2f\n", a2);
    printf("b = %.2f\n", b2);
    printf("Resultado = %.6lf\n\n", r2);

    // =========================
    double vetor[] = {
        0.0,
        1.0,
        2.0,
        3.0
    };

    int n = 4;

    double r3 = foo3(vetor, n);

    printf("=== foo3 ===\n");

    printf("Vetor:\n");

    for(int i = 0; i < n; i++) {
        printf("vetor[%d] = %.2lf\n", i, vetor[i]);
    }

    printf("Resultado = %.6lf\n", r3);

    return 0;
}
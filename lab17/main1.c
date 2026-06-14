#include <stdio.h>

double foo(double a, int b);

struct X {
    int vi;
    double vd;
    struct X *next;
};

struct X1 {
    int vi;
    float vf;
};

double pack(struct X *px);
double pack1(struct X1 *px, int n);

int main(void) {

    printf("=== TESTE FOO ===\n");
    printf("%.2f\n", foo(4.5, 2));
    printf("%.2f\n", foo(4.5, -2));
    printf("%.2f\n", foo(-4.5, 2));

    printf("\n=== TESTE PACK ===\n");

    struct X x3 = {4, 3.0, NULL};
    struct X x2 = {3, 2.0, &x3};
    struct X x1 = {2, 1.5, &x2};

    printf("%.2f\n", pack(&x1));

    printf("\n=== TESTE PACK1 ===\n");

    struct X1 v[] = {
        {2, 1.5f},
        {3, 2.0f},
        {4, 3.0f}
    };

    printf("%.2f\n", pack1(v, 3));

    return 0;
}
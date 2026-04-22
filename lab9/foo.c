#include <stdio.h>

void foo(int a[], int n);

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 0, 3, 4, 0, 5, 0};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Antes:\n");
    print_array(a, n);

    foo(a, n);

    printf("Depois:\n");
    print_array(a, n);

    return 0;
}
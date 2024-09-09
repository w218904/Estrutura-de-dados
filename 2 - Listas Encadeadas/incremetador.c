#include <stdio.h>

int main() {
    int a = 10;
    int b = 0;
    int j = 0;

    for (int i = 0; i <= 10; i++){
        b = ++ a;
        printf("Valor de a: %d\n", a);
        printf("Valor de b: %d\n", b);
    }
    printf("\n\n");
    a = 10;
    for (int i = 0; i <= 10; i++){
            j = a ++;
            printf("Valor de a: %d\n", a);
            printf("Valor de j: %d\n", j);
        }
}
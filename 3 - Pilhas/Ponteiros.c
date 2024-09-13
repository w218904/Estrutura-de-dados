#include <stdio.h>

int main() {
    int x = 10;          // Variável normal
    int *ptr = &x;       // Declaração de um ponteiro que armazena o endereço de `x`

    printf("Valor de x: %d\n", x);           // Acessa diretamente o valor de `x`
    printf("Endereço de x: %p\n", &x);       // Mostra o endereço de `x`
    
    printf("Valor de ptr: %p\n", ptr);       // Mostra o valor de `ptr`, que é o endereço de `x`
    printf("Valor apontado por ptr: %d\n", *ptr); // Desreferencia `ptr` e mostra o valor de `x`

    // Modifica o valor de `x` diretamente via scanf usando o endereço de `x`
    printf("Digite um novo valor para x: ");
    scanf("%d", &x);   // Passa o endereço de `x` para scanf, para modificar `x`

    printf("Novo valor de x: %d\n", x);      // Exibe o novo valor de `x`
    printf("Novo valor apontado por ptr: %d\n", *ptr); // Verifica o valor apontado por `ptr`, que também mudou

    return 0;
}

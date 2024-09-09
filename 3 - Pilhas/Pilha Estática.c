#include <stdio.h>
#include <stdlib.h>

/* Pilha estática */

typedef struct pilha{
       int topo;
       int item[10];
} T_PILHA;

/* Protótipos das funções */

int Inicializar_pilha      (T_PILHA *inicio);
int Inicializar2_pilha     (T_PILHA *inicio);
int Inserir_topo           (T_PILHA *inicio, int info);
int Remover_topo           (T_PILHA *inicio);
int Obter_topo             (T_PILHA inicio, int *dado);
int Verifica_vazio         (T_PILHA inicio, int *resp);

int main() {



    return 0;
}

int Inicializar_pilha (T_PILHA *inicio) {

    inicio->topo = -1;

    for(int i = 0; i <= 9; i++)
    {
        inicio->item[i] = 0;
    }

    return 0;
}

int Inicializar2_pilha (T_PILHA *inicio) {

    T_PILHA pilha_aux = {.topo = -1, .item = {0}};
    *inicio = pilha_aux;

    return 0;

}

int Inserir_topo (T_PILHA *inicio, int info) {

    if (inicio->topo >= 9) {
        return -1;
    }

    inicio->topo++;
    inicio->item[inicio->topo] = info;

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define Tam_Max 10

/* Pilha estática */

typedef struct pilha{
       int topo;
       int item[Tam_Max];
} T_PILHA;

/* Protótipos das funções */

int Inicializar_pilha      (T_PILHA *inicio);
int Inicializar2_pilha     (T_PILHA *inicio);
int Inserir_topo           (T_PILHA *inicio, int info);
int Listar_pilha           (T_PILHA inicio);
int Remover_topo           (T_PILHA *inicio);
int Listar_topo            (T_PILHA inicio, int *info);
int Pilha_cheia            (T_PILHA inicio);


/* Início da execução*/

int main() {

    T_PILHA pilha;
    int q, info, erro;
    erro = Inicializar_pilha(&pilha);
    do
    {
        system("clear");
	    printf("PILHA\n");
		printf("\n\nOpções:\n\n");
		printf("1 -> Inserir \n");
        printf("2 -> Listar toda pilha\n");
        printf("3 -> Remover\n");
        printf("4 -> Listar topo\n");
        printf("5 -> Verificar pilha cheia\n");
        printf("6 -> Sair\n");
        printf("Insira: ");
        scanf("%d", &q); //Ler a opção do usuário
        switch (q)
        {
        case (1):
            printf("Dado para inserção no topo da pilha: ");
            scanf("%d", &info);
            erro = Inserir_topo(&pilha, info);
            if (erro == 0)
            {
                printf("Dado inserido com sucesso!\n");
            }
            else
            {
                printf("Não foi possível inserir na pilha\n");
            }
            getchar();
            break;
        case (2):
            printf("---------PILHA---------\n");
            erro = Listar_pilha(pilha);
            if (erro == 0)
            {
                printf("Pilha listada com sucesso\n");
            }
            else
            {
                printf("Não foi possível listar a pilha\n");
            }
            getchar();
            break;
        case (3):
            erro = Remover_topo(&pilha);
            if (erro == 0)
            {
                printf("Dado removido com sucesso\n");
            }
            else
            {
                printf("Não foi possível remover da pilha\n");
            }
            getchar();
            break;
        case (4):
            erro = Listar_topo(pilha, &info);
            if (erro == 0)
            {
                printf("Valor do topo da pilha: %d\n", info);
            }
            else
            {
                printf("Não foi possível listar o topo da pilha\n");
            }
            getchar();
            break;
        case (5):
            erro = Pilha_cheia(pilha);
            if (erro == 1)
            {
                printf("A pilha está cheia\n");
            }
            else if (erro == 0) {
                printf("A pilha está vazia\n");
            }
            else
            {
                printf("A pilha não está cheia\n");
            }
            getchar();
            break;
        case (6):
            break;
        default:
            printf("\n\nOpção inválida\n");
        }
        getchar();
    } while (q != 6);
    


    return 0;
}

/* Funções da pilha estática */

int Inicializar_pilha (T_PILHA *inicio) {

    inicio->topo = -1;
    for (int i = 0; i < Tam_Max - 1; i++)
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

    if (inicio->topo >= Tam_Max - 1)
    {
        return -1;
    }
    else
    {
        inicio->topo++;
        inicio->item[inicio->topo] = info;
    }

    return 0;
}

int Listar_pilha (T_PILHA inicio) {

    if (inicio.topo < 0)
    {
        return -1;
    }
    else
    {
        while (inicio.topo >= 0)
        {
            printf("%d\t", inicio.item[inicio.topo]);
            inicio.topo--;
        }
    }
    printf("\n\n");

    return 0;
}

int Remover_topo (T_PILHA *inicio) {

    if (inicio->topo < 0)
    {
        return -1;
    }
    else
    {
        inicio->topo--;
    }

    return 0;
}

int Listar_topo (T_PILHA inicio, int *info) {

    if (inicio.topo < 0)
    {
        return -1;
    }
    else
    {
        *info = inicio.item[inicio.topo];
    }

    return 0;
}

int Pilha_cheia (T_PILHA inicio) {

    if (inicio.topo >= Tam_Max - 1)
    {
        return 1;
    }
    else if (inicio.topo == -1)
    {
        return 0;
    }
    else
    {
        return -1;
    }

}
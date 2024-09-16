//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------
#define tamanho 10  // tamanho maximo da FILA
/* -----------------------------------------------------------------------------
Estrutura FILA ESTATICA
------------------------------------------------------------------------------*/

typedef struct fila{
        int item [tamanho] ;
        int inicio, fim;
} T_FILA;




// ==================================================================
int  inicializa (T_FILA *f)
{
    (*f).inicio = -1;
    (*f).fim = -1;
    return 0;
}

// ==================================================================
int estado(T_FILA fila)
{
    if (fila.inicio == -1)
        return 0;  // fila vazia
    else {
        if ((fila.fim + 1) % tamanho == fila.inicio)
            return 1;   // fila cheia
        else
            return 2;  // fila não vazia com capacidade de armazenamento
    }
}

// ==================================================================
int insere(T_FILA *fila, int dado)
{

    int erro = estado (*fila);

    if (erro == 1)
    {
        return 1;
    }
    else
    {
        fila->fim = (fila->fim + 1) % tamanho;
        fila->item[fila->fim] = dado;// inserção efetuada
        if (fila->inicio == -1)
        {
            fila->inicio = 0;
        }
        return 0;
    }
}

// ==================================================================
int remover(T_FILA *fila) {

    int erro = estado (*fila);
    if (erro != 0)
    {
        if (fila->inicio == fila->fim) // Se há apenas um elemento na fila
        {
            fila->inicio = -1;
            fila->fim = -1;
        }
        else // Avança o índice de ínicio circularmente
        {
            fila->inicio = (fila->inicio + 1) % tamanho;
        }
        return 0; // Remoção bem-sucedida
    }
    else
    {
        return 1; // impossível remover. Underflow
    }
}

// ==================================================================
int listar(T_FILA fila)
{  
    int i,erro;
    erro = estado (fila);
    if (erro != 0)
    {
        int i = fila.inicio;
        do
        {
            printf("%d\t", fila.item[fila.inicio]);
            fila.inicio = (fila.inicio + 1) % tamanho;
        } while (fila.inicio != (fila.fim + 1) % tamanho);
        printf("\n");
        return 0;
    }
    else
    {
        return 1;  // não possível listar pois a fila esta vazia
    } 
}


// ==================================================================
int obter_primeiro(T_FILA fila, int *dado)
{  int i;
    if (fila.inicio == -1 )
       return 1;   // fila vazia
    else {
       *dado =  fila.item[fila.inicio];
       return 0;
    }
}
// ==================================================================
// ==================================================================

int main(void)
{

	int dado;
	int erro; /* valor de erro retornado pelas funcoes */
	T_FILA fila;


	int q;  /* receber a opcao do usuario */
	do {
	    system("clear");
	    printf("FILA Estatica \n");
		printf("\n\nOpcoes: \n\n");
		printf("1 -> Inicializa \n");
		printf("2 -> Insere\n");
		printf("3 -> Remove\n");
		printf("4 -> Verifica Estado de Vazio\n");
		printf("5 -> Lista \n");
		printf("6 -> Obter Primeiro \n");
		printf("7 -> \n");
		printf("8 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1:
                erro=inicializa (&fila);
                printf("\nInicializacao realizada com sucesso !\n");
                printf("\nFila VAZIA \n");
                getchar();
                break;
			case 2:
                printf("Dado para insercao: ");
                scanf("%d", &dado);
                erro = insere(&fila, dado);
                if (erro == 1)
                    printf("\nFila cheia. Overflow\n");
                getchar();
                break;
            case 3:
                erro = remover(&fila);
                if (erro == 1)
                    printf("\nFila Vazia. Underflow\n");
                getchar();
                break;
			case 4:
                erro = estado(fila);
                if (erro == 0)
                    printf("\nA fila esta vazia.\n");
                if (erro == 2)
                    printf("\nA fila esta em condicoes de uso\n");
                if (erro == 1)
                    printf("\nA fila esta cheia.\n");
                getchar();
                break;
			case 5:
                erro = listar(fila);
                if (erro == 1)
                    printf("\nA fila esta vazia.\n");
                getchar();
                break;
			case 6:
                erro = obter_primeiro(fila, &dado);
                if (erro == 0)
                {
                    printf("Dado no inicio: %d\n", dado);
                }
                else
                    printf("fila vazia. Sem primeiro\n");
                getchar();
                break;
			case 7:
				break;
			case 8: 
                break;
			default: 
                printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 8) );
}

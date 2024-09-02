#include <stdlib.h>
#include <stdio.h>


/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES - Com Descritor
------------------------------------------------------------------------------*/

typedef struct no_ls {
	int dado;
	struct no_ls *prox;
}  Tno_ls;

typedef struct descritor_ls {
	int tam;
	struct no_ls *prim;
	struct no_ls *ult;
} Tdescritorno_ls;


/* -----------------------------------------------------------------------------
Protótipos das funções
------------------------------------------------------------------------------*/
int Inicializar_LS      (Tdescritorno_ls *pdesc);
int Inserir_inicio_LS   (Tdescritorno_ls *pdesc, int info);
int Listar_LS           (Tdescritorno_ls cdesc);
int Copia_lista         (Tdescritorno_ls *L1, Tdescritorno_ls *L2);

int main(void)
{

	int info;
	int erro; /* valor de erro retornado pelas funções */
	Tdescritorno_ls desc, cdesc;
	int q;  /* receber a opção do usuário */
	erro = Inicializar_LS  (&desc);

    do {
	    system("clear");
        printf("\n");
	    printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no final\n");
		printf("3 -> Copiar lista para outra lista\n");
		printf("4 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opção do usuário */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&desc, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    getchar();
					break;
			case 2: printf("\n------ Lista com descritor ------\n");
                    int Listar_LS(cdesc);
                    getchar();
			        break;
            case 3: erro = Copia_lista(&desc, &cdesc);
                    if (erro ==0){
                        printf("\nLista copiada com sucesso!\n");
                    }
                    getchar();
                    break;
			case 4: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 4) );
}

int Inicializar_LS(Tdescritorno_ls *pdesc) {
    pdesc ->prim = NULL;
    pdesc ->ult = NULL;
    pdesc ->tam = 0;
}

int Inserir_inicio_LS (Tdescritorno_ls *pdesc, int info) {
    Tno_ls *no_novo, *aux;

    /* Criação do novo nó - Alocação de memória */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    if (pdesc -> tam ==0)
    { // lista vazia
        pdesc -> prim = no_novo;
        pdesc -> ult = no_novo;
        pdesc -> tam = 1;
    }
    else
    {  // lista não vazia
        aux = pdesc -> prim;
        pdesc -> prim = no_novo;
        no_novo -> prox = aux;    // ligando o novo nó com o 1º nó
        pdesc -> tam += 1;
    }
    return 0;


}

int Listar_LS (Tdescritorno_ls cdesc);

int Copia_lista (Tdescritorno_ls *L1, Tdescritorno_ls *L2) {

    Tdescritorno_ls *aux;
    Tno_ls *aux1, *aux2;
    int aux3, aux4;

    //aux1->dado = L1->prim->dado;
    aux1 = L1->prim;

    printf("%p\n", L1->prim);
    //printf("%d\n", L1->prim->dado);
    printf("%p\n", aux1);
    //printf("%d\n", aux1->dado);
    //printf("%d", aux->prim->dado);

    printf("\nFim da função Copiar Lista\n");
    
    return 0;
}
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
//#include <windows.h>
//---------------------------------------------------------------------------

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


// Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...


/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS      (Tdescritorno_ls *pdesc);
int Inicializar2_LS     (Tdescritorno_ls *pdesc);
int Inserir_inicio_LS   (Tdescritorno_ls *pdesc, int info);
int Inserir_fim_LS      (Tdescritorno_ls *pdesc, int info);
int Inserir_meio_LS     (Tdescritorno_ls *pdesc, int info, int pos);
int Remover_inicio_LS   (Tdescritorno_ls *pdesc);
int Remover_meio_LS     (Tdescritorno_ls *pdesc, int pos);
int Remover_fim_LS      (Tdescritorno_ls *pdesc);
int Listar_LS           (Tdescritorno_ls cdesc);
int Obter_dado_LS       (Tdescritorno_ls cdesc, int pos, int *dado);
int Obter_pos_LS        (Tdescritorno_ls cdesc, int dado, int *pos);
int Obter_Tamanho_LS    (Tdescritorno_ls cdesc, int *tam);
int Copia_lista         (Tdescritorno_ls *L1, Tdescritorno_ls *L2);

/* Variaveis global */



/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;
	int erro, erro2; /* valor de erro retornado pelas funcoes */
	Tdescritorno_ls desc, cdesc;
	int q;  /* receber a opcao do usuario */
	erro = Inicializar_LS  (&desc);
    erro2 = Inicializar_LS  (&cdesc);
	do {
	    //system("clear");
	    printf("\n1 -> Inserir no inicio \n");
		printf("2 -> Inserir no final\n");
		printf("3 -> Remover no inicio\n");
		printf("4 -> Mostrar toda a lista \n");
		printf("5 -> Inicializar a lista (versao 2)\n");
        printf("6 -> Copiar lista para outra lista\n");
		printf("7 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&desc, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    getchar();
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    //Inserir_fim_LS (&ini, info);
			        break;
            case 3: //erro = Remover_inicio_LS (&ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover");
                    }
                    getchar();
                    break;
			case 4: //erro=Listar_LS (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    getchar();
					break;
			case 5: //erro=Inicializar2_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    getchar();
					break;
            case 6: erro = Copia_lista(&desc, &cdesc);
                    if (erro ==0){
                        printf("\nLista copiada com sucesso!\n");
                    }
                    break;
			case 7: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 7) );

}

int Inicializar_LS      (Tdescritorno_ls *pdesc)
{
    pdesc ->prim = NULL;
    pdesc ->ult = NULL;
    pdesc ->tam = 0;
}

int Inserir_inicio_LS   (Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *no_novo, *aux;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    if (pdesc -> tam ==0)
    { // lista vazia
        pdesc -> prim = no_novo;
        pdesc -> ult = no_novo;
        pdesc -> tam = 1;
    }
    else
    {  // lista n�o vazia
        aux = pdesc -> prim;
        pdesc -> prim = no_novo;
        no_novo -> prox = aux;    // ligando o novo com o 1o no
        pdesc -> tam += 1;
    }
    return 0;
}



int Copia_lista (Tdescritorno_ls *L1, Tdescritorno_ls *L2) {

    Tdescritorno_ls *aux;
    Tno_ls *aux1, *aux2;
    int aux3, aux4;

    aux->prim = L1->prim;
    
    printf("%p", L1->prim);
    printf("%p", aux->prim);

/*     L2 = L1;

    printf("%p\n", L1->prim);
    printf("%p\n", L2->prim);
    printf("%d\n", L1->tam);
    printf("%d\n", L2->tam);
    printf("%p\n", L1->ult);
    printf("%p\n", L2->ult); */


/*     L2->prim = L1->prim;
    L2->tam = L1->tam;
    L2->ult = L1->ult;

    printf("%p\n", L1->prim);
    printf("%p\n", L2->prim);
    printf("%d\n", L1->tam);
    printf("%d\n", L2->tam);
    printf("%p\n", L1->ult);
    printf("%p\n", L2->ult); */

    printf("\nFim da função Copiar Lista\n");
    
    return 0;
}
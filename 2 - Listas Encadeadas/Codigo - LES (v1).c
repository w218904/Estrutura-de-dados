
#include <stdlib.h>
#include <stdio.h>


/* Estrutura LISTA ENCADEADA SIMPLES  ================ */

struct no_ls {
    char sexo;
    char nome[20];
	int dado;
	struct no_ls *prox;
};

typedef struct no_ls Tno_ls;


/* Prototipos das funcoes =========================== */

/* Apenas insere um 1o elemento na lista */
int Inserir_LS     (Tno_ls **p_inicio, int info);
/* Apenas remove o 1o elemento da lista */
int Remover_LS     (Tno_ls **p_inicio);
/* Apenas obtem o 1o dado da lista */
int Obter_dado_LS       (Tno_ls *c_inicio, int *p_info);



/* FUN��ES ========================================== */

int Obter_dado_LS     (Tno_ls *c_inicio, int *p_info)
{
    *p_info = c_inicio -> dado;
    return 0;
}

int Remover_LS     (Tno_ls **p_inicio)
{
    Tno_ls *aux, *aux2;
    if (*p_inicio == NULL)
       return 1;  // remo��o impossivel - lista vazia

    aux2 = *p_inicio;       // 1o. n�
    aux = aux2 -> prox;   // 2o. n�
    free(aux2); // removendo o 1o.
    *p_inicio = aux;  // indicando novo inicio da lista
    return 0;   // remo��o realizada
}


int Inserir_LS     (Tno_ls **p_inicio, int info)
{
    Tno_ls *aux, *p_novo;
    // criando o n�
    p_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    if (p_novo == 0) return 1;  // n�o h� memoria disponivel
    p_novo -> dado = info;
    p_novo -> prox = NULL;

	aux = *p_inicio; // 1
	*p_inicio = p_novo;  // 2   // estou fazendo o ini receber o endere�o do n� criado
    (*p_inicio) -> prox = aux; // 3

    return 0;  // inser��o realizada sem erros
}

/*PRINCIPAL ======================================= */
int main(void)
{

	int i, info;
	int erro; /* valor de erro retornado pelas funcoes */
	Tno_ls *inicio, *aux2;

	inicio = NULL; // indicar a lista vazia

	printf("Digite 1o. valor: ");
	scanf("%d", &info);
    erro = Inserir_LS (&inicio, info);
    if (erro != 0) printf("Nao foi possivel a insercao. \n");

	printf("Digite 2o. valor: ");
	scanf("%d", &info);
    erro = Inserir_LS (&inicio, info);
    if (erro != 0) printf("Nao foi possivel a insercao. \n");

    printf("Digite 3o. valor: ");
	scanf("%d", &info);
    erro = Inserir_LS (&inicio, info);
    if (erro != 0) printf("Nao foi possivel a insercao. \n");

    printf("Digite 4o. valor: ");
	scanf("%d", &info);
    erro = Inserir_LS (&inicio, info);
    if (erro != 0) printf("Nao foi possivel a insercao. \n");


    aux2 = inicio;
    for (i=1;i<=4;i++)
    {
        printf("Valor: %d\n", aux2->dado);
        aux2 = aux2 -> prox;
    }
    // ===============================================
    erro = Obter_dado_LS (inicio, &info);
    if (erro != 0)
        printf("Nao foi possivel obter \n");
    else
        printf("O primeiro: %d \n", info);


    Remover_LS (&inicio);

    // ===============================================
    erro = Obter_dado_LS (inicio, &info);
    if (erro != 0)
        printf("Nao foi possivel obter \n");
    else
        printf("O primeiro: %d \n", info);


}





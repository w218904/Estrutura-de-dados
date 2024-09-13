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
int Inicializar2_LS     (Tdescritorno_ls *pdesc);
int Inserir_inicio_LS   (Tdescritorno_ls *pdesc, int info);
int Inserir_fim_LS      (Tdescritorno_ls *pdesc, int info);
int Inserir_meio_LS     (Tdescritorno_ls *pdesc, int info, int pos);
int Inserir_aleatorio_LS(Tdescritorno_ls *pdesc);
int Remover_inicio_LS   (Tdescritorno_ls *pdesc);
int Remover_meio_LS     (Tdescritorno_ls *pdesc, int pos);
int Remover_fim_LS      (Tdescritorno_ls *pdesc);
int Listar_LS           (Tdescritorno_ls cdesc);
int Obter_dado_LS       (Tdescritorno_ls cdesc, int pos, int *dado);
int Obter_pos_LS        (Tdescritorno_ls cdesc, int dado, int *pos);
int Obter_Tamanho_LS    (Tdescritorno_ls cdesc, int *tam);
int Copia_lista         (Tdescritorno_ls *L1, Tdescritorno_ls *L2);

int main(void)
{

	int info, pos, tam;
	int erro; /* valor de erro retornado pelas funções */
	Tdescritorno_ls desc, cdesc;
	int q;  /* receber a opção do usuário */
	erro = Inicializar_LS (&desc);

    do {
	    system("clear");
        printf("\n");
	    printf("01 -> Inserir no início\n");
        printf("02 -> Inserir no meio da lista\n");
        printf("03 -> Inserir no final \n");
        printf("04 -> Inserir dados aleatórios na lista\n");
		printf("05 -> Listar lista\n");
        printf("06 -> Remover no início da lista\n");
        printf("07 -> Remover no meio da lista\n");
        printf("08 -> Remover no final da lista\n");
		printf("09 -> Copiar lista para outra lista\n");
        printf("10 -> Obter dado da lista\n");
        printf("11 -> Obter posição do dado na lista\n");
        printf("12 -> Obter o tamanho da lista\n");
		printf("13 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opção do usuário */
		switch(q) {
			case 1: 
                printf("Dado para insercão no início lista: ");
                scanf("%d",&info);
                erro = Inserir_inicio_LS (&desc, info);
                if (erro == 0) 
                {
                    printf("Insercao realizada com sucesso\n");
                }
                getchar();
                break;
            case 2: 
                printf("Dado para inserção no meio da lista: ");
                scanf("%d", &info);
                printf("Posição que deve ser inserido: ");
                scanf("%d", &pos);
                erro = Inserir_meio_LS(&desc, info, pos);
                if (erro == 0) 
                {
                    printf("Inserção no meio da lista bem sucedida\n");
                } 
                else 
                {
                    printf("Não foi possível inserir no meio da lista\n");
                }
                getchar();
                break;
            case 3: 
                printf("Dado para inserção no final da lista: ");
                scanf("%d", &info);
                erro = Inserir_fim_LS (&desc, info);
                getchar();
                break;
            case 4: 
                erro = Inserir_aleatorio_LS(&desc);
                if (erro == 0)
                {
                    printf("Dados aleários inseridos na lista\n");
                } 
                else 
                {
                    printf("Impossível inserir dados aleatórios\n");
                }
                getchar();
                break;
			case 5: 
                printf("\n------ Lista com descritor ------\n\n");
                erro = Listar_LS(desc);
                if (erro == 0)
                {
                    printf("\n\nFim da exibição da lista\n");
                } 
                else 
                {
                    printf("\nImpossível listar, lista vazia!\n");
                }
                
                getchar();
                break;
            case 6: 
                erro = Remover_inicio_LS(&desc);
                if (erro == 0)
                {
                    printf("Início removido com sucesso\n");
                }
                getchar();
                break;
            case 7: 
                printf("Posição que deve ser removido: ");
                scanf("%d", &pos);
                erro = Remover_meio_LS(&desc, pos);
                if (erro == 0)
                {
                    printf("Remoção no meio da lista bem sucedida\n");
                }
                else
                {
                    printf("Não foi possível remover no meio da lista\n");
                }
                getchar();
                break;
            case 8: 
                erro = Remover_fim_LS(&desc);
                if (erro == 0)
                {
                    printf("Final removido com sucesso\n");
                }
                getchar();
                break;
            case 9:
                Inicializar_LS(&cdesc);
                erro = Copia_lista(&desc, &cdesc);
                if (erro == 0)
                {
                    printf("\nLista copiada com sucesso!\n");
                    Listar_LS(cdesc);
                } 
                else 
                {
                    printf("Lista vazia, impossível copiar");
                }
                getchar();
                break;
            case 10:
                printf("Selecione a posição que gostaria de obter o dado: ");
                scanf("%d", &pos);
                erro = Obter_dado_LS(desc, pos, &info);
                if (erro == 0)
                {
                    printf("O dado dessa posição é: %d\n", info);
                }
                else
                {
                    printf("Não foi possível obter o dado dessa posição\n");
                }
                getchar();
                break;
            case 11:
                printf("Insira o dado que gostaria de ober a posição: ");
                scanf("%d", &info);
                erro = Obter_pos_LS(desc, info, &pos);
                if (erro == 0)
                {
                    printf("A posição desse dado é: %d\n", pos);
                }
                else
                {
                    printf("Não foi possível obter a posição desse dado\n");
                }
                getchar();
                break;
            case 12:
                //printf("O tamanho da lista é: %d", desc.tam); //jeito mais simples
                erro = Obter_Tamanho_LS(desc, &tam);
                if (erro == 0)
                {
                    printf("O tamanho da lista é: %d", tam);
                }
                
                getchar();
                break;
			case 13: 
                break;
			default: 
                printf("\n\n Opcao não válida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 13));
}

int Inicializar_LS (Tdescritorno_ls *pdesc) {
    pdesc ->prim = NULL;
    pdesc ->ult = NULL;
    pdesc ->tam = 0;

    return 0;
}

int Inserir_inicio_LS (Tdescritorno_ls *pdesc, int info) {
    Tno_ls *no_novo;

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
        no_novo->prox = pdesc->prim;
        pdesc->prim = no_novo;
        pdesc->tam++;
    }

    return 0;


}

int Inserir_meio_LS (Tdescritorno_ls *pdesc, int info, int pos) {

    Tno_ls *novo_no, *aux;
    int tam = 1;
    
    novo_no = (Tno_ls*)malloc(sizeof(Tno_ls));
    novo_no->dado = info;

    if (pos == 1)
    {
        Inserir_inicio_LS(pdesc, info);
    } 
    else if (pos > 1 && pos < pdesc->tam) 
    {
        aux = pdesc->prim;
        while (tam < pos - 1)
        {
            aux = aux->prox;
            tam++;
        }
        novo_no->prox = aux->prox;
        aux->prox = novo_no;
        pdesc->tam++;
    } 
    else if (pos == pdesc->tam) 
    {
        Inserir_fim_LS(pdesc, info);
    } 
    else 
    {
        printf("Posição incompatível com tamanho da lista\n");
        return 1;
    }

    return 0;
}

int Inserir_fim_LS (Tdescritorno_ls *pdesc, int info) {

    Tno_ls *novo_no;

    novo_no = (Tno_ls*)malloc(sizeof(Tno_ls));

    if (!pdesc && !novo_no)
    {
        printf("Impossível inserir no final da lista\n");

        if(novo_no)
        {
            free(novo_no);
        }

        return 1;
    }

    novo_no->dado = info;

    if (pdesc->tam == 0)
    {
        pdesc->prim = novo_no;
        pdesc->ult = novo_no;
    }
    else
    {
        pdesc->ult->prox = novo_no;
        pdesc->ult = novo_no;
    }

    pdesc->tam++;

    return 0;
}

int Inserir_aleatorio_LS (Tdescritorno_ls *pdesc) {

    Tno_ls *novo_no, *aux = NULL;

    for (int i = 1; i <= 10; i++)
    {
        novo_no = (Tno_ls *) malloc(sizeof(Tno_ls));
        novo_no->dado = rand() % 100;   // Gera um valor aleatório para o dado do novo_no
        novo_no->prox = pdesc->prim;  // Novo nó aponta para o antigo primeiro nó
        pdesc->prim = novo_no;    // Atualiza o início da lista para o novo nó
        pdesc->tam++;   // Incrementa o tamanho da lista
        if (i == 1)
        {
            aux = novo_no;
        }
    }
    pdesc->ult = aux;

    return 0;
}

int Listar_LS (Tdescritorno_ls cdesc) {

    if (cdesc.prim == NULL)
    {
        return 1;
    }
    

    while (cdesc.prim)
    {
        printf("%d\t", cdesc.prim->dado);
        cdesc.prim = cdesc.prim->prox;
    }

    printf("\n\nTamanho da lista: %d", cdesc.tam);

    return 0;
}

int Remover_inicio_LS   (Tdescritorno_ls *pdesc) {
    
    Tno_ls *aux;
    if (!pdesc->prim)
    {
        printf("Lista vazia, impossível remover\n");
        return 1;
    }
    else
    {
        aux = pdesc->prim;
        pdesc->prim = pdesc->prim->prox;
        pdesc->tam--;
        free(aux);
    }

    return 0;
}

int Remover_meio_LS (Tdescritorno_ls *pdesc, int pos) {

    printf("Função Remover_meio_LS chamada\n");
    Tno_ls *aux, *aux2;
    int tam = 1;

    aux = pdesc->prim;
    while (tam < pos - 1)
    {
        aux = aux->prox;
        tam++;
    }
    aux2 = aux->prox;
    aux = aux2->prox;
    free(aux2);

    return 0;
}

int Remover_fim_LS (Tdescritorno_ls *pdesc) {

    Tno_ls *aux, *aux2;

    if (!pdesc->prim)
    {
        printf("Lista vazia, impossível remover\n");
        return 1;
    }
    else
    {
        aux = pdesc->prim;
        while (aux->prox != pdesc->ult)
        {
            aux = aux->prox;
        }
        aux2 = pdesc->ult;
        pdesc->ult = aux;
        aux->prox = NULL;
        free(aux2);
        pdesc->tam--;
    }
    
    return 0;
}

int Copia_lista (Tdescritorno_ls *L1, Tdescritorno_ls *L2) {

    Tno_ls *aux;

    if (L1->prim == NULL)
    {
        return 1;
    }
    

    aux = L1->prim;
    while (aux) 
    {
        Inserir_inicio_LS (L2, aux->dado);
        aux = aux->prox;
    }
    
    return 0;
}

int Obter_dado_LS (Tdescritorno_ls cdesc, int pos, int *dado) {

    int tam = 1;
    Tno_ls *aux;

    aux = cdesc.prim;
    while (tam != pos)
    {
        aux = aux->prox;
        tam++;
    }
    *dado = aux->dado;

    return 0;
}

int Obter_pos_LS (Tdescritorno_ls cdesc, int dado, int *pos) {

    *pos = 1;
    while (cdesc.prim->dado != dado)
    {
        cdesc.prim = cdesc.prim->prox;
        (*pos)++;
    }

    return 0;
}

int Obter_Tamanho_LS (Tdescritorno_ls cdesc, int *tam) {

    *tam = cdesc.tam;

    return 0;
}
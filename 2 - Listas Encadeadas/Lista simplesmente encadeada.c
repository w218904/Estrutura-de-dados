#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
}Data;

typedef struct {
    //char nome;
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa() {
    Pessoa p;

    //printf("\nDigite nome: \n");
    //scanf("%s", p.nome);
    printf("\nDigite o dia: \n");
    scanf("%d", &p.data.dia);
    printf("\nDigite o mês: \n");
    scanf("%d", &p.data.mes);
    printf("\nDigite o ano: \n");
    scanf("%d", &p.data.ano);

    return p;
}

void imprimir_pessoa (Pessoa p) {

    printf("Data: %2d/%2d/%4d",/*p.nome,*/ p.data.dia, p.data.mes, p.data.ano);
}

//função para a operação push (empilhar)
No* empilhar(No *topo) {

    No *no_novo = (No *) malloc(sizeof(No));

    if (no_novo) {
        no_novo->p = ler_pessoa();
        no_novo->proximo = topo;

        return no_novo;        
    } else {
        printf("\nErro ao alocar memória...\n");
        
        return NULL;
    }

}

No* desempilhar(No **topo) {
    
    if(*topo != NULL) {
        No *aux = *topo;
        *topo = aux->proximo;
        //free(aux);

        return aux;
    } else {
        printf("\nPilha vazia!\n");

        return NULL;
    }

}

void Imprimir_pilha(No *topo) {

    if (topo != NULL) {
        printf("\n-------- PILHA --------\n");
        while (topo != NULL) {
            imprimir_pessoa(topo->p);
            printf("\n\n");
            topo = topo->proximo;
        }
        printf("\n------ FIM PILHA ------\n");
        
    } else {
        printf("\nPilha vazia!\n");
    }
    

}

int main() {

    No *remover, *topo = NULL;
    int opcao;

    do
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover) {
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);
            } else {
                printf("\nSem nó a remover.\n");
            }
            break;
        case 3:
            Imprimir_pilha(topo);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    

    return 0;
}

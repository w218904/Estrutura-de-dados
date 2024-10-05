#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------- */
/* -------------------- ESTRUTURA DA MATRIZ ESPARSA */

typedef struct no_matriz {
    int dado;
    int poslinha, poscoluna;   /* posicao do número em relação aos vetores */
    struct no_matriz *dir, *esq, *acima, *abaixo;
} Tipo_no_matriz;

typedef struct vetor {
    int pos;
    struct no_matriz *pont; // inicio da lista
} Vetor_de_matriz;

Vetor_de_matriz vlinha[10], vcoluna[10]; // AQUI ESTÁ A MATRIZ ESPARSA

/* ------------------------------------------------- */
/* ------------------------------------------------- */

void clear_screen() {
    printf("\033[H\033[J"); // Código ANSI para limpar a tela
}

int Listar() {
    Tipo_no_matriz *percorre;
    int i;
    for (i = 1; i <= 9; i++) {
        printf("Linha [%d] ", i);
        percorre = vlinha[i].pont;
        while (percorre != NULL) {
            printf(" (%d.%d,%d) ", percorre->dado, percorre->poslinha, percorre->poscoluna);
            percorre = percorre->dir;
        }
        printf("\n");
    }
    getchar();
    return 0;
}

int Listar2() {
    Tipo_no_matriz *percorre;
    int i, j, x;
    x = 1;

    printf("\n");
    for (j = 0; j < 81; j += 9) {
        printf("[%d]", x);
        x++;
    }
    printf("\n");

    for (i = 1; i <= 9; i++) {
        percorre = vlinha[i].pont;
        while (percorre != NULL) {
            printf("\033[%d;%dH(%d)", percorre->poslinha + 7 + i, (percorre->poscoluna - 1) * 9, percorre->dado);
            percorre = percorre->dir;
        }
    }
    printf("\n");
    getchar();
    return 0;
}

/* ---------------------------------------------------- */
int Inicializar() {
    int i;
    for (i = 1; i <= 9; i++) {
        vcoluna[i].pont = NULL;
        vlinha[i].pont = NULL;

        vcoluna[i].pos = i;
        vlinha[i].pos = i;
    }
    return 0;
}

/* -------------------------- Verifica se célula já usada */
int ver(int linha, int coluna) {
    Tipo_no_matriz *percorre;
    percorre = vlinha[linha].pont;

    while ((percorre != NULL) && ((percorre->poscoluna != coluna) || (percorre->poslinha != linha))) {
        percorre = percorre->dir;
    }
    return (percorre == NULL) ? 0 : 1; // 0: célula não usada, 1: célula já existe
}

/* ----------------------------------------------------*/
int Inserir(int info, int linha, int coluna) {
    int erro;
    /* Verifica se célula já está ocupada */
    erro = ver(linha, coluna);
    if (erro == 1) return 1; // Já existe dado nesta coordenada

    Tipo_no_matriz *percorre, *percorreantes, *no_novo;

    /* criar novo nó */
    no_novo = (Tipo_no_matriz *)malloc(sizeof(Tipo_no_matriz));
    no_novo->dado = info;
    no_novo->dir = NULL;
    no_novo->esq = NULL;
    no_novo->acima = NULL;
    no_novo->abaixo = NULL;
    no_novo->poslinha = linha;
    no_novo->poscoluna = coluna;

    if (vlinha[linha].pont == NULL) /* linha vazia */
    {
        vlinha[linha].pont = no_novo;
    } else {
        percorre = vlinha[linha].pont;
        percorreantes = NULL;
        while ((percorre != NULL) && (percorre->poscoluna < coluna)) {
            percorreantes = percorre;
            percorre = percorre->dir;
        }
        if (percorre == NULL) {
            /* inserção no final */
            percorreantes->dir = no_novo;
            no_novo->esq = percorreantes;
        } else {
            /* inserção no início */
            if (percorreantes == NULL) {
                vlinha[linha].pont = no_novo;
                no_novo->dir = percorre;
                percorre->esq = no_novo;
            } else {
                /* inserção no meio */
                percorreantes->dir = no_novo;
                no_novo->esq = percorreantes;
                percorre->esq = no_novo;
                no_novo->dir = percorre;
            }
        }
    }
    if (vcoluna[coluna].pont == NULL) /* coluna vazia */
    {
        vcoluna[coluna].pont = no_novo;
    } else {
        percorre = vcoluna[coluna].pont;
        percorreantes = NULL;
        while ((percorre != NULL) && (percorre->poslinha < linha)) {
            percorreantes = percorre;
            percorre = percorre->abaixo;
        }
        if (percorre == NULL) {
            /* inserção no final */
            percorreantes->abaixo = no_novo;
            no_novo->acima = percorreantes;
        } else {
            /* inserção no início */
            if (percorreantes == NULL) {
                vcoluna[coluna].pont = no_novo;
                no_novo->abaixo = percorre;
                percorre->acima = no_novo;
            } else {
                /* inserção no meio */
                percorreantes->abaixo = no_novo;
                no_novo->acima = percorreantes;
                percorre->acima = no_novo;
                no_novo->abaixo = percorre;
            }
        }
    }
    return 0;
}

int Remover(int linha, int coluna) {
    Tipo_no_matriz *percorre, *percorreantes;

    // Verifica se a célula existe
    if (!ver(linha, coluna)) {
        printf("A célula (%d,%d) não existe.\n", linha, coluna);
        return 1; // Indica que a célula não foi encontrada
    }

    // Remove da lista da linha
    percorre = vlinha[linha].pont;
    percorreantes = NULL;
    while (percorre != NULL && (percorre->poscoluna != coluna)) {
        percorreantes = percorre;
        percorre = percorre->dir;
    }

    // Atualiza os ponteiros na lista da linha
    if (percorre) {
        if (percorreantes == NULL) {
            // Remoção do primeiro elemento
            vlinha[linha].pont = percorre->dir;
        } else {
            // Remoção do elemento do meio ou final
            percorreantes->dir = percorre->dir;
        }
    }

    // Remove da lista da coluna
    percorre = vcoluna[coluna].pont;
    percorreantes = NULL;
    while (percorre != NULL && (percorre->poslinha != linha)) {
        percorreantes = percorre;
        percorre = percorre->abaixo;
    }

    // Atualiza os ponteiros na lista da coluna
    if (percorre) {
        if (percorreantes == NULL) {
            // Remoção do primeiro elemento
            vcoluna[coluna].pont = percorre->abaixo;
        } else {
            // Remoção do elemento do meio ou final
            percorreantes->abaixo = percorre->abaixo;
        }
    }

    // Libera a memória do nó removido
    free(percorre);
    return 0; // Indica sucesso na remoção
}


int main(void) {
    int info, linha, coluna;
    int q, erro;
    do {
        clear_screen();
        printf(" Opcao \n");
        printf("1. Inserir \n");
        printf("2. Inicializar \n");
        printf("3. Listar \n");
        printf("4. Remover \n");
        printf("5. Sair \n");
        scanf("%d", &q);
        if (q == 1) {
            printf(" Dados= ");
            scanf("%d", &info);
            printf(" Linha= ");
            scanf("%d", &linha);
            printf(" Coluna= ");
            scanf("%d", &coluna);
            erro = Inserir(info, linha, coluna);
            if (erro != 0) printf("Insercao impossivel.\n");
            printf("Pressione Enter para continuar...");
            getchar(); // Limpa o buffer
            getchar(); // Espera pelo Enter
        } else if (q == 2) {
            Inicializar();
        } else if (q == 3) {
            Listar2();
            printf("Pressione Enter para continuar...");
            getchar(); // Limpa o buffer
            getchar(); // Espera pelo Enter
        } else if (q == 4) {
            printf(" Linha= ");
            scanf("%d", &linha);
            printf(" Coluna= ");
            scanf("%d", &coluna);
            erro = Remover(linha, coluna);
            if (erro != 0) printf("Remocao impossivel.\n");
            printf("Pressione Enter para continuar...");
            getchar(); // Limpa o buffer
            getchar(); // Espera pelo Enter
        }
    } while (q != 5);
    return 0;
}


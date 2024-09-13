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
int Remover_topo           (T_PILHA *inicio);
int Obter_topo             (T_PILHA inicio, int dado);
int Verifica_vazio         (T_PILHA inicio, int resp);

int main() {

    int info;
	int erro, resposta; /* valor de erro retornado pelas funções */
	T_PILHA ini;

	int q;  /* receber a opção do usuário */
	erro = Inicializar_pilha (&ini);
	do {
	    system("clear");
	    printf("PILHA\n");
		printf("\n\nOpcoes:\n");
		printf("1 -> Inserir \n");
        printf("2 -> Listar\n");
		printf("3 -> Remover\n");
		printf("4 -> Inicializar\n");
		printf("5 -> Consultar Topo \n");
		printf("6 -> Verificar Vazio\n");
		printf("7 -> Sair \n\n:");
		scanf("%d", &q);     /* Ler a opção do usuário */
		switch(q) {
			case 1: printf("Dado para insercao na Pilha: ");
                    scanf("%d",&info);
                    erro = Inserir_topo (&ini, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    getchar();
					break;
            case 2: printf("Valores na pilha estática:\n");
                    erro = Listar_pilha(ini);
                    if (erro == 0)
                    {
                        printf("Pilha exibida com sucesso\n");
                    }
                    else
                    {
                        printf("Não foi possível listar a pilha");
                    }
                    getchar();
                    break;
                    
            /* case 3: erro = Remover_topo (ini);
                    if (erro==1)
                    {
                        printf("\nPilha vazia. Impossivel remover.\n");
                    }
                    getchar();
                    break;
            case 4: erro = Inicializar2_pilha (ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nPILHA VAZIA !\n");
                    getchar();
					break;
			case 5: erro = Obter_topo (ini, &info);
                    if (erro==1)
                    {
                        printf("\nPilha vazia. Impossivel consultar topo\n");
                    }
                    else {
                         printf("\nTopo: %d\n", info);
                    }
                    getchar();
					break;
			case 6: erro= Verifica_vazio (ini, &resposta);
                    if (resposta==1)
                    {
                        printf("\nPilha vazia\n");
                    }
                    else {
                         printf("\nPilha nao vazia\n");
                    }
                    getchar();
					break; */
			case 7: break;
			default: printf("\n\n Opcao nao valida\n");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 7) );


    return 0;
}

int Inicializar_pilha (T_PILHA *inicio) {

    inicio->topo = -1;

    for(int i = 0; i <= Tam_Max; i++)
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

    if (inicio->topo >= Tam_Max - 1) {
        return -1;
    }

    inicio->topo++;
    inicio->item[inicio->topo] = info;

    return 0;
}

int Listar_pilha (T_PILHA inicio) {
     
     if (inicio.item[inicio.topo] < 0)
     {
        printf("Lista vazia\n");
     }
    else
    {
        while (0 <= inicio.item[inicio.topo])
        {
            printf("%d\n", inicio.item[inicio.topo]);
            inicio.item[inicio.topo--];
        }
     }
    
    return 0;
}

/* int Remover_topo (T_PILHA *inicio) {

    if(inicio->topo < 0) {
        return -1;
    }

    inicio->topo--;
    inicio->item[inicio->topo] = 0;

    return 0;
}

int Obter_topo (T_PILHA inicio, int dado) {

    dado = inicio.item[inicio.topo];

    return 0;
}

int Verificar_vazio (T_PILHA inicio, int resp) {

    if (inicio.item[inicio.topo] >= 0)
    {
        resp = 0;
    }
    else
    {
        resp = 1;
    }    

    return 0;    
} */
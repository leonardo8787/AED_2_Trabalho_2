#include "avl.h"
#include "avl.h"

int main(){

	system("cls || clear");
	
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	int num;

	printf("\nTrabalho de AED 2\n\n");
	printf("Professor Michel");
	printf("autor: Leonardo Campos\n");
	
	do{
	    printf("Escolha uma opção: \n");
	    printf("0 - sair\n");
	    printf("1 - inserir valor\n");
	    printf("2 - remover\n");
	    printf("3 - imprimir árvore\n");
	    printf("4 - limpar tela\n");
	    printf("5 - Leia a atividade!\n");
	    scanf("%d", &num);
	    switch(num){
	        case 0:
	            printf("\nSaindo...\n");
	            return 0;
	            break;
	        case 1:
	            printf("\nDigite um valor: ");
	            scanf("%d", &num);
	            r.key = num;
	            r.value = 1;
	            insertTree(&raiz, r);
	            break;
	        case 2:
	            printf("\nDigite um número para remover: \n");
	            scanf("%d", &num);
	            r.key = num;
	            removeTree(&raiz, &raiz, r);
	            break;
	        case 3:
	            printf("\nÁrvore\n");
	            printf("[");
	            central(raiz);
	            printf("fim]");
	            printf("\n");
	            break;
	        case 4:
	           	system("cls || clear");
	           	break;
	        case 5:
	        	printf("Apartir do conjunto de dados {10,2,7,5,3,9,16,4,11,1,6,23,14} "
	        		"faça: 1 2 Construa a árvore AVL a partir dos conceitos de inserção apresentados,"
	        		"lembre-se que a cada execução deste procedimento é preciso verificar "
	        		"se a estrutura está balanceada e executar os devidos procedimentos para"
	        		"manter a mesma de acordo com as suas especificações. Efetue a remoção dos seguintes elementos:"
	        		"{10,5,4,11,6}. Como fica a estrutura após cada remoção? Repita os passos "
	        		"acima definidos para o seguinte conjunto de dados: {78,44,67,92,22,110,16,54,23,32,37}.\n");
	        	break;
	        default:
	            printf("\nEscolha uma opção válida!\n");
	            break;
	    }
	}while(num);

    return 0;
}
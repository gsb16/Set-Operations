#include <stdio.h>
#include <stdlib.h>
#include "funcconj.h"

int main(){
	int k, n;
	int ***ptam, *temp;
	char op;

	scanf("%d ", &k);
	ptam = (int ***)malloc((k+1)*sizeof(int***));

	for(int i = 0; i < k+1; i++){
		ptam[i] = (int **) malloc(1*sizeof(int*));
		ptam[i][0] = (int *) malloc(1*sizeof(int));
		ptam[i][0][0] = 0;
	}

	scanf("%c ", &op);
	while (op != '0'){
		if (op != '*'){
			scanf("%d ", &n);
			temp = (int *) malloc(n*sizeof(int));
			for (int i = 0; i < n; i++){
				scanf("%d ", &temp[i]);
			}
		}

		int resul;
		switch (op){
			case '+' :
				resul =	incluiconjunto(ptam, temp, n, k);
				if(resul == -1){
					printf("E\n");
				}
				printf("0\n");
			break;

			case '-' :
				resul = removeconjunto(ptam, temp, n);
				if(resul == -1){
					printf("E\n");
				}
				printf("0\n");
			break;

			case '=' :
				if (ptam[n][0][0] == 0)
				{
					printf("E\n");
				} else {
					int pos = buscaconjunto(ptam, temp, n);
					if(pos <= ptam[n][0][0]){
						if (compara(ptam[n][pos], temp, n) != 0)
						{
							printf("E\n");
						}
					} else {
						printf("E\n");
					}
				}
				printf("0\n");
			break;

			case '*' :
				listacolecao(ptam, k);
			break;

			case '>' :
				listasuperconjuntos(ptam, temp, n, k);
				printf("0\n");
			break;

			case '<' :
				listasubconjuntos(ptam, temp, n, k);
				printf("0\n");
			break;

			case '/' :
				if(!removesuperconjuntos(ptam, temp, n, k)){
					printf("E\n");
				} else {
					printf("0\n");
				}
			break;

			default :
				printf("Operação não reconhecida\n");
		}

		scanf("%c ", &op);
	}

	for(int i = 0; i < k+1; i++){
		free(ptam[i][0]);
		free(ptam[i]);
	}

	free(ptam);

	return 0;
}

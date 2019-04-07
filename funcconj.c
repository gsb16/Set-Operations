#include <stdio.h>
#include <stdlib.h>
#include "funcconj.h"

int compara(int *prim, int *seg, int n){
	int delta;

	for (int i = 0; i < n; ++i){
		delta = prim[i] - seg[i];
		if (delta != 0){
			return (delta);
		}
	}

	return (delta);
}

int buscaconjunto(int ***ptam, int *ptemp, int n){
	int i;
	if(ptam[n][0][0]){
		for(i = 1; i <= ptam[n][0][0]; i++){
			if(compara(ptam[n][i], ptemp, n) >= 0){
				return i;
			}
		}
	}

	return i;
};

int listacolecao(int ***ptam, int k){
	for (int i = 1; i <= k; ++i){
		if(ptam[i][0][0]){
			for(int b = 1; b <= ptam[i][0][0]; b++){
				printf("%d ", i);
				for (int j = 0; j < i-1; ++j){
					printf("%d ", ptam[i][b][j]);
				}
				printf("%d\n", ptam[i][b][i-1]);
			}
		}
	}

	printf("0\n");

	return 0;
}

int incluiconjunto(int ***ptam, int *ptemp, int n, int k){
	int pos;
	if(ptam[n][0][0]){
		pos = buscaconjunto(ptam, ptemp, n);
		if(pos <= ptam[n][0][0]){
			if(compara(ptam[n][pos], ptemp, n) == 0){
				return -1;
			}
		}
	} else {
		pos = 1;
	}
	ptam[n][0][0] += 1;
	ptam[n] = (int **)realloc(ptam[n], sizeof(int *) * (ptam[n][0][0]+1));
	for(int i = ptam[n][0][0]; i > pos; i--){
		ptam[n][i] = ptam[n][i-1];
	}
	ptam[n][pos] = ptemp;

	return 0;
}

int removeconjunto(int ***ptam, int *ptemp, int n){
	int pos = 0;
	if(ptam[n][0][0] == 0){
		return -1;
	} else {
		pos = buscaconjunto(ptam, ptemp, n);
		if(pos <= ptam[n][0][0]){
			if(compara(ptam[n][pos], ptemp, n) != 0){
				return -1;
			}
		} else {
			return -1;
		}
	}
	free(ptam[n][pos]);
	for(int i = pos; i < ptam[n][0][0]; i++){
		ptam[n][i] = ptam[n][i+1];
	}

	ptam[n][0][0] -= 1;

	ptam[n] = (int **)realloc(ptam[n], sizeof(int *) * (ptam[n][0][0]+1));

	return 0;
}

int superconjunto(int *orig, int *candi, int n, int nc){
	int ic = 0, iguais = 0;
	for(int i = 0; i < n; i++){
		while((candi[ic] < orig[i]) && (ic <= nc)){
			ic += 1;
		}
		if(candi[ic] == orig[i]){
			iguais += 1;
		} else {
			return 0;
		}
	}

	return (iguais == n);
}

int listasuperconjuntos(int ***ptam, int *ptemp, int n, int k){
	int ok = 0;
	for(int i = n+1; i <= k; i++){
		for(int j = 1; j <= ptam[i][0][0]; j++){
			if(superconjunto(ptemp, ptam[i][j], n, i)){
				ok = 1;
				printf("%d ", i);
				for(int h = 0; h < i-1; h++){
					printf("%d ", ptam[i][j][h]);
				}
				printf("%d\n", ptam[i][j][i-1]);
			}
		}
	}
	return ok;
}

int listasubconjuntos(int ***ptam, int *ptemp, int n, int k){
	int ok = 0;
	for(int i = 1; i <= n-1; i++){
		for(int j = 1; j <= ptam[i][0][0]; j++){
			if(superconjunto(ptam[i][j], ptemp, i, n)){
				ok = 1;
				printf("%d ", i);
				for(int h = 0; h < i-1; h++){
					printf("%d ", ptam[i][j][h]);
				}
				printf("%d\n", ptam[i][j][i-1]);
			}
		}
	}
	return ok;
}

int removesuperconjuntos(int ***ptam, int *ptemp, int n, int k){
	int ok = 0;
	for(int i = n+1; i <= k; i++){
		for(int j = 1; j <= ptam[i][0][0]; j++){
			if(superconjunto(ptemp, ptam[i][j], n, i)){
				ok = 1;

				free(ptam[i][j]);
				for(int h= j; h < ptam[i][0][0]; h++){
					ptam[i][h] = ptam[i][h+1];
				}
				ptam[i][0][0] -= 1;
				ptam[i] = (int **)realloc(ptam[i], sizeof(int *) * (ptam[i][0][0]+1));
				j -= 1;
			}
		}
	}
	return ok;
}

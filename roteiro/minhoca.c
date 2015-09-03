#include <stdio.h>

int main(){

	int n, m, i, j, l[105], soma, maior = 0;

	scanf("%d %d", &n, &m);

	for(i=0; i<n; i++){
		soma = 0;
		for(j=0; j<m; j++){
			scanf("%d", &l[i][j]);
			soma += l[i][j];
		}
		if(soma > maior) maior = soma;
	}

	for(i=0; i<m; i++){
		soma = 0;
		for(j=0; j<n; j++){
			soma += m[j][i];
		}
		if(soma > maior) maior = soma;
	}

	printf("%d\n", maior);
	return 0;
}
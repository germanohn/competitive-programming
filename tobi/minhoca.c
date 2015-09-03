#include <stdio.h>

int main(){

	int campo[100][100],i,j,n,m,soma_linha,maior=0,soma_coluna;

	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++){
		soma_linha=0;
		for(j=0;j<m;j++){
			scanf("%d",&campo[i][j]);
			soma_linha+=campo[i][j];
		}
		if(soma_linha>maior) maior=soma_linha;
	}

	for(i=0;i<m;i++){
		soma_coluna=0;	
		for(j=0;j<n;j++){
			soma_coluna+=campo[j][i];
		}
		if(soma_coluna>maior) maior=soma_coluna;
	}

	printf("%d\n",maior);

	return 0;
}
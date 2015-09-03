#include <stdio.h>

int main(){

	int mapa[100][100],i,j,k,n,tmp;

	scanf("%d",&n);

	for(j=0;j<n;j++){
		for(k=0;k<n;k++){
			scanf("%d",&mapa[j][k]);
		}
	}
	
	for(j=0;j<n;j++){
		for(k=0;k<n;k++){
			scanf("%d",&tmp);
			mapa[j][k]+=tmp;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mapa[i][j]);
		}
		printf("\n");
	}

	return 0;
}	
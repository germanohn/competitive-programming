#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 110

int main(){
	int n,k,i,j,menor;
	char nome[MAX][25],aux[MAX][25];

	scanf("%d %d",&n,&k);

	for(i=1;i<=n;i++) scanf("%s",nome[i]);

	for(i=1;i<n;i++){
		menor=i;
		for(j=i+1;j<=n;j++){
			if(strcmp (nome[menor],nome[j]) > 0){
				menor=j;
			}	
		}
		if(menor!=i){
			strcpy(aux[i],nome[i]);
			strcpy(nome[i],nome[menor]);
			strcpy(nome[menor],aux[i]);
		}
	}

	printf("%s",nome[k]);
	printf("\n");
	return 0;	
}
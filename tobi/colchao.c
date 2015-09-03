#include <stdio.h>

int main(){

	int v[3],maior,menor,i,j,aux,min;

	scanf("%d %d %d %d %d",&v[0],&v[1],&v[2],&maior,&menor);

	if(maior<menor){
		aux=maior;
		maior=menor;
		menor=aux;
	}

	for(i=0;i<2;i++){
		min=i;
		for(j=i+1;j<3;j++){
			if(v[min]>v[j]){
				min=j;
			}
		}
		if(min!=i){
			aux=v[i];
			v[i]=v[min];
			v[min]=aux;
		}
	}

	if(v[0]<=menor && v[1]<=maior){
		printf("S\n");
	}

	else{
		printf("N\n");
	}

	return 0;
}
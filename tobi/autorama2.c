#include <stdio.h>

int main(){

	int c,carro[100],copia[100],seq[100],leit,posto,i,j,aux,maior,num,ant;

	scanf("%d %d %d",&posto,&c,&leit);

	for(i=0;i<=c;i++) carro[i]=0;

		
	for(i=1;i<=leit;i++){

		scanf("%d %d",&num,&posto);
		carro[num]=posto;
		v[num]=leit;

	}

	for(i=1;i<=c;i++){
		copia[i]=carro[i];
	}

	for(i=1;i<c;i++){
		maior=i;
		for(j=i+1;j<=c;j++){
			if(copia[maior]<copia[j]) maior=j;
		}

		if(maior!=i){
			
			aux=copia[i];
			copia[i]=copia[maior];
			copia[maior]=aux;
		}
	}
	

	for(i=1;i<=c;i++){
		for(j=1;j<=c;j++){
			if(copia[i]==carro[j]){
				seq[i]=j;
				carro[j]=0;
				break;
			}
		}
	}

	for(i=1;i<=c;i++){
		printf("%d ",seq[i]);
	}
	printf("\n");
	return 0;
}
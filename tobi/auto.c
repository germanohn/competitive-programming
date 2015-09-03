#include <stdio.h>

int main(){

	typedef struct{
		int leitura;
		int posto;
		int num;
	} Tipo;

	Tipo carro[100];
	Tipo aux;

	int i,post,leit,c,num,maior,menor,j,k,l;

	scanf("%d %d %d",&post,&c,&leit);

	for(i=1;i<=leit;i++){
		scanf("%d %d",&num,&post);
		carro[num].posto=post;//guarda o numero de postos do carro num
		carro[num].leitura=i;//guarda a leitura na qual o carro passou pelo seu ultimo posto
		carro[num].num=num;//guarda o numero do carro na posiçao i
	}

	for(i=1;i<=c;i++){
		printf("posto=%d num=%d leitura=%d\n", carro[i].posto,carro[i].num,carro[i].leitura);
	}

	//como iremos imprimir decrescente com i
	for(i=1;i<c;i++){
		maior=i;
		for(j=i+1;j<=c;j++){
			if(carro[maior].posto<carro[j].posto){
				maior=j;
			}
		}
		if(maior!=i){
			aux = carro[i];
			carro[i] = carro[maior];
			carro[maior] = aux;
		}
	}
	for(i=1;i<=c;i++){
		printf("posto=%d num=%d leitura=%d\n", carro[i].posto,carro[i].num,carro[i].leitura);
	}
	
	//agora se tiver algum igual faz o sort novamente
	for(i=1;i<=c;i++){
		if(i!=c){
			if(carro[i].posto != carro[i+1].posto){
				printf("%d ",carro[i].num);
			}
		
			else{
				j=i+2;
				while(carro[j].posto == carro[i].posto){
					j++;
				}
				//printf("j=%d\n",j);
				for(k=i;k<j-1;k++){
					menor=k;
					for(l=k+1;l<j;l++){
						if(carro[menor].leitura > carro[l].leitura){
							menor=l;
						}
					}
					if(menor!=k){
						aux = carro[k];
						carro[k] = carro[menor];
						carro[menor] = aux;
					}
					printf("%d ",carro[k].num);
				}	
				printf("%d ",carro[k].num);
				i=j-1;
				printf("j=%d i=%d\n",j,i);
			}
		}
		else{
			printf("%d ",carro[i].num);
		}			
	}
	printf("oi\n");

	return 0;
}
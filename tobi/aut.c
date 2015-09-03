#include <stdio.h>

int main(){

	typedef struct{
		int leitura;
		int posto;
		int num;
		int ult;
	} Tipo;

	Tipo carro[110];
	Tipo aux;

	int i,post,leit,c,num,maior,menor,j,p,l,k;

	scanf("%d %d %d",&p,&c,&leit);

	for(i=1;i<=c;i++){
		carro[i].posto=0;
		carro[i].ult=0;
	}

	for(i=1;i<=leit;i++){
		scanf("%d %d",&num,&post);
		carro[num].num=num;
		if(carro[num].ult == post-1){
			carro[num].posto++;
			carro[num].leitura=i;
			carro[num].ult=post%p;
		}	
	}

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
		if(i!=c){
			if(carro[i].posto != carro[i+1].posto){
				printf("%d ",carro[i].num);
			}
			else{
				j=i+2;
				while(carro[j].posto == carro[i].posto){
					j++;
				}
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
			}
		}
		else{
			printf("%d ",carro[i].num);
		}			
	}
	printf("\n");

	return 0;
}
#include <stdio.h>

int main(){

	int c,carro[100],copia[100],seq[100],leitura[100],leit,posto,marco,i,j,aux,menor,maior,num,ant,k,l,p;
	int h,passei;

	scanf("%d %d %d",&posto,&c,&leit);

	for(i=0;i<=c;i++) carro[i]=0;

		
	for(i=1;i<=leit;i++){

		scanf("%d %d",&num,&posto);
		carro[num]=posto;
		leitura[num]=i;
			
	}

	for(i=1;i<=c;i++){
		copia[i]=carro[i];
	}

	for(i=1;i<c;i++){
		maior=i;
		
		for(j=i+1;j<=c;j++)
			if(copia[maior]<copia[j]) 
				maior=j;

		if(maior!=i){
			aux=copia[i];
			copia[i]=copia[maior];
			copia[maior]=aux;
		}
	}

	i=1;
	while(i<=c){
		k=0;
		for(j=1;j<=c;j++){
			if(copia[i]==carro[j]){
				k++;
				marco=j;		
			}
		}
		
		if(k==1){
			seq[i]=marco;
			i++;
		}
		else{
			l=i;
			
			while(l<i+k){
				passei=0;
				for(h=i;h<i+k;h++){
					menor=leitura[h];
					if(menor!=0) break;
				}
				
				for(p=i;p<i+k;p++){
					
					if(leitura[p]<menor && leitura[p]!=0){
						menor=leitura[p];
						aux=p;
						passei=1;
					}
				}
				if(passei==0){
					aux=h;
					
				}
				leitura[aux]=0;
				seq[l]=aux;
				l++;
			}
			i=i+k;
		}
		
	}

	for(i=1;i<=c;i++){
		printf("%d ",seq[i]);
	}
	printf("\n");
	return 0;
}
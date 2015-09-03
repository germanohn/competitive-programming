#include <stdio.h>

int main(){

	typedef struct{
		int ident;
		int num;
	} Country;

	Country pais[100],aux;

	int n,m,clas[100],o,p,b,i,j,maior,k,menor,l;

	scanf("%d %d",&n,&m);

	//cada pais recebe o seu identificador
	for(i=1;i<=n;i++){
		pais[i].ident=i;
	}

	for(i=1;i<=n;i++){
		pais[i].num=0;
	}

	//cada pais soma seu numero de medalhas
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&o,&p,&b);
		pais[o].num++;
		pais[p].num++;
		pais[b].num++;
	}
	
	for(i=1;i<=n;i++){
		printf("%d ",pais[i].num);
	}
	printf("\n");

	//agora ordeno pelo numero de medalhas
	for(i=1;i<n;i++){
		maior=i;
		for(j=i+1;j<=n;j++){
			if(pais[maior].num < pais[j].num){
				maior=j;
			}
			else if(pais[maior].num == pais[j].num){
				if(pais[maior].ident > pais[j].ident) maior=j;
			}
		}
		if(maior != i){
			aux=pais[i];
			pais[i]=pais[maior];
			pais[maior]=aux;
		}
	}

	for(i=1;i<=n;i++){
		printf("%d ",pais[i].ident);
	}
	printf("\n");

	for(i=1;i<=n;i++){
		printf("%d ",pais[i].num);
	}
	printf("\n");

	for(i=1;i<=n;i++) printf("%d ",pais[maior].ident);

	printf("\n");	
	/*for(i=1;i<=n;i++){
		if(i!=n){
			if(pais[i].num != pais[i+1].num){
				printf("%d ",pais[i].ident);
			}
			else{
				j=i+2;
				while(pais[j].num == pais[i].num){
					j++;
				}
				for(k=i;k<j-1;k++){
					menor=k;
					for(l=k+1;l<j;l++){
						if(pais[menor].ident > pais[l].ident){
							menor=l;
						}
					}
					if(menor!=k){
						aux = pais[k];
						pais[k] = pais[menor];
						pais[menor] = aux;
					}
					printf("%d ",pais[k].ident);
				}	
				printf("%d ",pais[k].ident);
				i=j-1;
			}
		}
		else{
			printf("%d ",pais[i].ident);
		}			
	}	*/

/*
			if(pais[i].num == pais[i+1].num){
			if(pais[i].ident < pais[i].ident) printf("%d ",pais[i].ident);
			else printf("%d ",pais[i+1].ident);
		}
		else{
			printf("%d ",pais[i].ident);
		}
	}*/

	return 0;
}
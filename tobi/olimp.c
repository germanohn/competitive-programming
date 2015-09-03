#include <stdio.h>

int main(){

	typedef struct{
		int ident;
		int num;
	} Country;

	Country pais[105],aux;

	int n,m,o,p,b,i,j,maior,k,menor,l;

	scanf("%d %d",&n,&m);

	for(i=1;i<=n;i++){
		pais[i].ident=i;
	}

	for(i=1;i<=n;i++){
		pais[i].num=0;
	}

	for(i=1;i<=m;i++){
		scanf("%d %d %d",&o,&p,&b);
		pais[o].num++;
		pais[p].num++;
		pais[b].num++;
	}

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

	for(i=1;i<=n;i++) printf("%d ",pais[i].ident);

	printf("\n");	

	return 0;
}
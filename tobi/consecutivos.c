#include <stdio.h>

int main(){

	int atual,anterior,cont=1,maior=1,n;

	scanf("%d",&n);
	scanf("%d",&anterior);

	while(n>1){

		scanf("%d",&atual);

		if(atual==anterior){
			cont+=1;
			if(cont>maior)maior=cont;
		}

		else{
			cont=1;
		}

		anterior=atual;
		n--;
	}

	printf("%d\n",maior);

	return 0;
}
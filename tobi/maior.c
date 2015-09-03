#include <stdio.h>

int main(){

	int maior,tmp;

	scanf("%d",&maior);
	tmp=maior;

	while(tmp!=0){
		scanf("%d",&tmp);
		if(tmp>maior)maior=tmp;
	}

	printf("%d\n",maior);

	return 0;
}

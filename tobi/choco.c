#include <stdio.h>

int main(){
	int n,num,soma=0;

	scanf("%d",&n);

	while(n>0){
		scanf("%d",&num);
		soma+=num-1;
		n--;
	}

	printf("%d\n",soma);

	return 0;
}
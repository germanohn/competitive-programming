#include <stdio.h>

int main(){

	int a,b,c,quant;

	scanf("%d %d %d",&a,&b,&c);

	quant=a/2;

	if(quant>b/3){
		quant=b/3;
	}

	if(quant>c/5){
		quant=c/5;
	}

	printf("%d\n",quant);
	return 0;
}
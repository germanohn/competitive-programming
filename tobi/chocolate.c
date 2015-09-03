#include <stdio.h>

int main(){

	int pedacos=1;
	float l;

	scanf("%f",&l);

	while(l>=2){

		pedacos=4*pedacos;
		l=l/2;
	}

	printf("%d\n",pedacos);
	return 0;
}
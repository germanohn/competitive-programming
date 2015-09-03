#include <stdio.h>

int main(){

	int n, c, s, e, soma, cont = 0;

	scanf("%d %d", &n, &c);

	soma = 0;
	while(n > 0){

		scanf("%d %d", &s, &e);

		soma = soma + e - s;
		n--;
		if(soma > c){
			printf("S\n");
			cont = 1;
			break;
		} 
	}
	if(cont == 0) printf("N\n");

	return 0;
}
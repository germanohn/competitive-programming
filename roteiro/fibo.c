#include <stdio.h>

int main(){

	int n, soma, ant, atu;

	scanf("%d", &n);

	ant = 0;
	atu = 1;
	if(n == 1) printf("%d\n", ant);

	else if(n == 2) printf("%d %d\n", ant, atu);
	
	else{
		printf("%d %d ", ant, atu);
		while(n > 2){
			soma = ant + atu;
			if(n == 3) printf("%d", soma);

			else printf("%d ", soma);

			ant = atu;
			atu = soma;
			n --;
		}
		printf("\n");
	}	
	return 0;
}
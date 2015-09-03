#include <stdio.h>

/*ideia: um retângulo é formado por dois pares. entao conta-se primeiro quantos pares se tem 
de cada, e depois para contar quantos retângulos conta-se quantos pares de pares se tem.*/
int main(){

	int n, soma, a, b;

	while(scanf("%d", &n) && n != 0){

		soma = 0;
		while(n > 0){
			scanf("%d %d", &a, &b);
			soma = soma + b/2;
			n--;
		}
		printf("%d\n", soma / 2);	
	}
	return 0;
}
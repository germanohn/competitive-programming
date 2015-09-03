#include <stdio.h>
/*ideia : pega o primeiro operando e depois em um loop vai pegando um operador e um operando.
de dois em dois vai fazendo a operaçao*/
int main(){

	int m, cont, a, b;
	char op;

	cont = 1;
	while(scanf("%d", &m) && m != 0){

		scanf("%d", &a);
		while(m > 1){

			scanf("%c %d", &op, &b);

			if(op == '+') a += b;

			else a -= b;

			m--;
		}
		printf("Teste %d\n%d\n\n", cont, a);
		cont ++;
	}
	return 0;
}
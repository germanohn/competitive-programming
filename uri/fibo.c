#include <stdio.h>

int fib(int n, int *cont){

	if(n == 0) return 0;
	if(n == 1) return 1;

	if(n > 1){
		*cont += 2;	
		return fib(n-1, cont) + fib(n-2, cont);
	} 
}

int main(){

	int n, a, b, cont;

	scanf("%d", &n);
	while(n > 0){
		
		scanf("%d", &a);
		
		cont = 0;
		b = fib(a, &cont);

		printf("fib(%d) = %d calls = %d\n", a, cont, b);
	
		n--;
	}	
	
	return 0;
}
#include <stdio.h>

int main(){

	int a, b, c, k, menor, maior, n;

	scanf("%d %d %d", &a, &b, &c);

	menor = a;
	if(b < a && b < c) menor = b;
	
	else if(c < a && c < b) menor = c; 

	for(k = 0; k <= menor; k++){
		n = (a - k)/3 + (b - k)/3 + (c - k)/3 + k;
		if(n > maior) maior = n;
		
	}	
	printf("%d\n", maior);

	return 0;
}
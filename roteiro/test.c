#include <stdio.h>

int fat(int n){
	if(n == 0)
		return 1;
	else
		return fat(n-1) * n;
	
}

int main(){
	long long int a, b, soma;
	long long int oi;
	printf("oi\n");

	while(scanf("%lld %lld", &a, &b) != EOF){
		printf("%d %d\n", fat(a), fat(b));

		oi = 1932053504 + 1932053504;
		printf("oi = %lld\n", oi);
		soma = fat(a) + fat(b);
		printf("%lld\n", soma);
	}

	return 0;
}
#include <stdio.h>
#define MAX 10005
/*tenho um vetor resto-r, indexado de 1 a n-1 em que cada indice da posiçao é um resto, 
e na posiçao tem o indice i do vetor-v ate qual foi a soma acumulada.assim toda vez soma
mais um v[i] se a casa, cujo indice é o resto de soma por n, ja esta ocupada. se ja estiver entao
...*/
int main(){

	int r[MAX];
	int v[MAX];
	int n, soma, i, j;

	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		
		scanf("%d", &v[i]);
		
		if(v[i] % n == 0){
			printf("1\n%d\n", v[i]);
			return 0;
		}
	}

	for(i = 1; i <= n; i++) r[i] = -1;
	
	soma = v[1];
	
	r[v[1] % n] = 1;
	
	for(i = 2; i <= n; i++){

		soma += v[i];
		if(r[soma % n] != -1){

			printf("%d\n", i - r[soma % n]);
			
			for(j = r[soma % n] + 1; j <= i; j++){
				printf("%d\n", v[j]);
			}
			return 0;
		}
		else r[soma % n] = i; 
	}
}
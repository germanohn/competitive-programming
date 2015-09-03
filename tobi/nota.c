#include <stdio.h>
#define MAX 105

int main(){

	int n, i, aux, v[MAX], a, maior, num;

	for(i = 0; i < MAX; i++) v[i] = 0;

	scanf("%d", &n);
	aux = n;
	while(aux > 0){
		scanf("%d", &a);
		v[a]++;
		aux--;
	}
	
	maior = 0;
	for(i = 0; i < MAX; i++){
		if(v[i] != 0){
			if(v[i] >= maior){
				maior = v[i];
				num = i;
			}
		}
	}
	printf("%d\n", num);
	return 0;
}
#include <stdio.h>
#define MAX 500005

int main(){

	int n, m, i, a, v[MAX], aux, achei;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		v[i] = 0;
	}

	aux = n;
	i = 0;
	while(aux > 0){
		scanf("%d", &v[i]);
		aux--;
		i++;
	}
	i--;

	scanf("%d", &m);

	aux = m;
	while(aux > 0){
		scanf("%d", &a);
		achei = 0;
		for(i = 0; i < n && !achei; i++){
			if(a == v[i]){
				achei = 1;
				v[i] = 0;
			}
		}
		aux--;
	}

	for(i = 0; i < n; i++){
		if(v[i] != 0) printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}
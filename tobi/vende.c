#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b){
	return( *(int*)a - *(int*)b );
}

int main(){

	int n,k,dist,aux,i,j,tmp,pilha[100005],menor;

	scanf("%d %d",&n,&k);

	for(i=0 ; i<n; i++){
		scanf("%d", &pilha[i]);
	}

	qsort(pilha, n, sizeof(int), compare);

	i=0;
	j=n-1-k;
	dist = 10000000;

	while(i <= k && j < n){

		tmp = pilha[j] - pilha[i];
		if (tmp < dist) dist = tmp;
		i++;
		j++;
	}

	printf("%d\n", dist);

	return 0;
}
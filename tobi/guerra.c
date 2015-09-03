#include <stdio.h>

int main(){

	int secao,seq[100000],i,ant=0,dep=0;

	scanf("%d",&secao);
	
	for(i=0;i<secao;i++){
		scanf("%d",&seq[i]);
		dep=dep+seq[i];;
	}
	
	dep=dep-seq[0];
	ant=seq[0];

	for(i=1;i<secao;i++){
		if(ant==dep) break;

		else{
			ant=ant+seq[i];
			dep=dep-seq[i];
		}
	}

	printf("%d\n",i);
	return 0;
}
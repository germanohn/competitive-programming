#include <stdio.h>

int main(){

	int painel=0,n,i;
	char tipo;

	scanf("%d",&n);

	i=0;
	while(i<=n){

		scanf("%c",&tipo);

		if(tipo=='P') painel+=2;

		else if(tipo=='C') painel+=2;

		else if(tipo=='A') painel+=1;

		i++;
	}

	printf("%d\n",painel);

	return 0;
}
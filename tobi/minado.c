#include <stdio.h>

int main(){

	int campo[51],minado[51],i,n,cont=0;

	scanf("%d",&n);

	for(i=1;i<=n;i++){
		scanf("%d",&campo[i]);
	}

	if(campo[1]==1) cont++;
	if(campo[2]==1) cont++;
	minado[1]=cont;

	cont=0;
	if(campo[n]==1) cont++;
	if(campo[n-1]==1) cont++;
	minado[n]=cont;

	for(i=2;i<n;i++){
		cont=0;
		if(campo[i]==1) cont++;
		if(campo[i-1]==1) cont++;
		if(campo[i+1]==1) cont++;
		minado[i]=cont;
	}	

	for(i=1;i<=n;i++){
		printf("%d\n",minado[i]);
	}

	return 0;
}
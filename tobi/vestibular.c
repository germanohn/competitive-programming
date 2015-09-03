#include <stdio.h>

int main(){

	int cont=0,i,n;
	char gab[80],fez[80];

	scanf("%d\n",&n);

	for(i=0;i<n;i++){
		scanf("%c",&gab[i]);
		
	}

	for(i=0;i<n;i++){
		scanf("\n%c",&fez[i]);
		if(gab[i]==fez[i]) cont++;
		
	}

	printf("%d\n",cont);

	return 0;
}
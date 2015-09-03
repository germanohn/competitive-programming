#include <stdio.h>

int main(){

	int latas,copos,n,quebrou;

	scanf("%d",&n);

	while(n>0){

		scanf("%d %d",&latas,&copos);

		if(latas>copos) quebrou+=copos;

		n--;
	}

	printf("%d\n",quebrou);

	return 0;
}
#include <stdio.h>

int main(){

	int i,reg[1000002],num,cont,n;

	scanf("%d",&n);

	for(i=0;i<1000002;i++) reg[i]=0;

	for(i=0;i<n;i++){
		scanf("%d",&num);
		reg[num]++;
	}

	for(i=0;i<1000002;i++){
		if(reg[i]!=0) cont++;
	}

	printf("%d\n",cont);

	return 0;
}
#include <cstdio>
#include <cmath>

int main(){

	int n,teste,fator;
	scanf("%d",&n);

	teste=1;
	while(n!=0){
		printf("Teste %d\n",teste);
		fator=pow(2,n);
		printf("%d\n\n",fator-1);
		teste++;
		scanf("%d",&n);
	}

	return 0;
}
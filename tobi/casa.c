#include <stdio.h>

int main(){
	int num[100005],n,k,j,i,soma,cont=0;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}

	scanf("%d",&k);

	i=0;
	j=n-1;

	//primeira soluçao
	while(num[i] + num[j] != k){
		if(num[i] + num[j] > k) j--; //diminui um do maior
		else i++; //aumenta um do menor
	}

	printf("%d %d\n",num[i],num[j]);
	//segunda soluçao: mais lenta
	/*for(j=0;j<n-1;j++){
		soma=num[j];
		for(i=j+1;i<n;i++){
			soma+=num[i];
			if(soma==k){
				printf("%d %d\n",num[j],num[i]);
				cont=1;
				break;
			}
			soma=num[j];
		}
		if(cont==1) break;
	}*/	

	return 0;
}
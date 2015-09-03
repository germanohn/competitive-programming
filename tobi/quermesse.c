#include <stdio.h>

int main(){

	int sort[10000],i,n,j;

	j=1;
	scanf("%d",&n);
	while(n!=0){
		
		for(i=1;i<=n;i++){
			scanf("%d",&sort[i]);
			if(sort[i]==i){
				printf("Teste %d\n%d\n\n",j,sort[i]);
			}
		}
		j++; 
		scanf("%d",&n);
	}
	
	return 0;	
}


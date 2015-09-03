#include <stdio.h>

int main(){

	int raio[500000][2],i,k,n,cont=0;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		for(k=0;k<2;k++){
			scanf("%d",&raio[i][k]);
		}
	}

	for(i=0;i<n;i++){
		for(k=i+1;k<n;k++){
			if(raio[i][0]==raio[k][0] && raio[i][1]==raio[k][1]){
				cont=1;
				break;
			}	
		}
		if(cont==1){
			break;
		}
	}

	if(cont==0){
		printf("0\n");
	}

	else{
		printf("1\n");
	}

	return 0;
}
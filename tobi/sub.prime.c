	#include <stdio.h>

int main(){

	int fundo[20],n,banco,i,v,d,c;

	scanf("%d %d",&banco,&n);

	while(banco!=0 && n!=0){

		for(i=1;i<=n;i++){
			scanf("%d",&fundo[i]);
		}

		for(i=1;i<=n;i++){
			scanf("%d %d %d",&d,&c,&v);

			fundo[d]-=v;
			fundo[c]+=v;
		}
		
		for(i=1;i<=n;i++){
			if(fundo[i]<0){
				printf("N\n");
				break;
			}
		}
		i--;
		if(i==n) printf("S\n");

		scanf("%d %d",&banco,&n);	
	}
	return 0;
}
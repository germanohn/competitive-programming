#include <stdio.h>

int main(){

	int t,n,k,b[105],q,m,i,a;
	scanf("%d",&t);
	while(t>0){
		scanf("%d %d",&n,&k);
		a=0;
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
			a+=b[i]/k;
		}
		t--;
		printf("%d\n",a);
	}

	return 0;
}
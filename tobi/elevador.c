#include <stdio.h>

int main(){

	int num,cap,sai,ent,esta=0;

	scanf("%d %d",&num,&cap);

	while(num>0){

		scanf("%d %d",&sai,&ent);

		esta=esta-sai+ent;

		if(esta>cap) 
			break;

		num--;
	}
	
	if(num==0) printf("N\n");

	else printf("S\n");

	return 0;
}
#include <stdio.h>

int main(){

	 int v[3],min,j,i,aux;

	 for(i=0;i<3;i++){
	 	scanf("%d",&v[i]);
	 }

	 for(i=0;i<2;i++){
	 	min=i;
	 	for(j=i+1;j<3;j++){
	 		if(v[min]>v[j]){
	 			min=j;
	 		}
	 	}
	 	if(min!=i){
	 		aux=v[i];
	 		v[i]=v[min];
	 		v[min]=aux;
	 	}
	 }

	 printf("%d\n",v[1]);

	 return 0;
}
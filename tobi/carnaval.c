#include <stdio.h>

int main(){

	float notas[5],final,aux;
	int i,j,min;

	for(i=0;i<5;i++){
		scanf("%f",&notas[i]);
	}

	for(i=0;i<4;i++){
		min=i;
		for(j=i+1;j<5;j++){
			if(notas[min]>notas[j]){
				min=j;
			}
		}
		if(min!=i){
			aux=notas[i];
			notas[i]=notas[min];
			notas[min]=aux;
		}
	}
	final=notas[1]+notas[2]+notas[3];
	printf("%.1f\n",final);

	return 0;
}
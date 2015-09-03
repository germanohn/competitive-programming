#include <stdio.h>

int main(){

	int m[105][105], i, j, n, cont;

	while(scanf("%d", &n) && n != 0){

		for(i=0; i<n; i++){
			cont = i+1;
			
			for(j=0; j<n; j++){
				
				if(j < i){
					m[i][j] = cont;
					cont --;
				}
				else if(j == i){
					m[i][j] = 1;
				}
				else if(j > i){
					cont ++;
					m[i][j] = cont;
				}
			}
		}

		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(j == n-1){
					printf("%3d", m[i][j]);
					printf("\n");
				} 

				else printf("%3d ", m[i][j]);
			}
		}		
		printf("\n");
	}
	return 0;
}
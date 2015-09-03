#include <stdio.h>

int main(){

	int n, i, j, m[75][75];

	while(scanf("%d", &n) != EOF){

		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				m[i][j] = 0;
			}
		}
		i=1;
		j=1;
		while(i <= n){
			m[i][j] = 1;
			m[i][n + 1 - j] = 2;
			i++; 
			j++;
		}

		for(i=1; i<=n; i++){
			for(j=1; j<=n; j++){
				if(m[i][j] == 0){
					m[i][j] = 3;
				}
				printf("%d", m[i][j]);
			}	
			printf("\n");
		}	
	}
	return 0;
}
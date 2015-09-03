#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(){

	int m[105][105], i, j, n, aux, ini, ok;

	while(scanf("%d", &n) && n != 0){
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				m[i][j] = 0;
			}
		}	

		aux = n;
		ini = 0;
		ok = TRUE;
		while(ok){
			for(i=ini; i<n; i++){
				for(j=ini; j<n; j++){
					m[i][j] += 1;
				}
			}
			if(n - 2 < 0) ok = FALSE;/*condiçao para ter submatriz. se passar 
			por essa condiçao entao volta para o incremento do for mas com agora a submatriz(
			sem a primeira e ultima linha da matriz original e a primeira e ultima colunas da matriz original)
			faz esse processo ate nao ser mais possivel fazer submatriz*/

			n--;
			ini++;
		}	

		for(i=0; i<aux; i++){
			for(j=0; j<aux; j++){
				if(j == aux-1){
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
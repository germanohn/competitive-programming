#include <stdio.h>

int main(){

	int m[10][10], i, j, cont, aux, ok, n;

	scanf("%d", &n);

	while(n > 0){
	
		scanf("%d", &m[1][1]);

		aux = 1;
		//preenche a matriz com os numeros de entrada 
		for(i=2; i<10; i++){
			cont = i - aux;//numero de caras que vao entrar na linha em questao
			ok = 0;	
			for(j=1; j< 10  && cont > 0; j++){

				if(i%2 != 0 && j%2 != 0){
					scanf("%d", &m[i][j]);
					cont --;
					ok = 1;
				}

				else m[i][j] = 0;
			}
			if(ok) aux ++;
		}
		m[9][2] = (m[7][1] - m[9][1] - m[9][3])/2;
		m[9][4] = (m[7][3] - m[9][3] - m[9][5])/2;
		m[9][6] = (m[7][5] - m[9][5] - m[9][7])/2;
		m[9][8] = (m[7][7] - m[9][7] - m[9][9])/2;

		for(i=8; i>1; i--){
			cont = i;
			for(j=1; cont > 0; j++){
			
				if(m[i][j] == 0){
					m[i][j] = m[i+1][j] + m[i+1][j+1];
				}
				cont --;
			}
		}

		for(i=1; i<=9; i++){
			cont = i;
			for(j=1; cont > 0; j++){
				
				if(cont > 1) printf("%d ", m[i][j]);

				else printf("%d", m[i][j]);
				cont --;
			}
			printf("\n");
		}
		n--;
	}	
	return 0;
}
#include <stdio.h>
#define ESQUERDA 1
#define CIMA 2
#define DIREITA 3
#define BAIXO 4

int main(){

	int	l, c, n, a, b, i, j, cont, dir;
	char tab[105][105], tmp;

	while(scanf("%d %d %d", &l, &c, &n) && l != 0 && c != 0 && n != 0){

		cont = 0;
		for(i=0; i<l; i++){
			for(j=0; j<c; j++){
				scanf("\n%c", &tab[i][j]);
				if(tab[i][j] == 'O' || tab[i][j] == 'N' || tab[i][j] == 'L' || tab[i][j] == 'S'){
					a = i;
					b = j;
				}
			}
		}

		if(tab[a][b] == 'O') dir = ESQUERDA;
		else if(tab[a][b] == 'N') dir = CIMA;
		else if(tab[a][b] == 'L') dir = DIREITA;
		else if(tab[a][b] == 'S') dir = BAIXO;

		while(n > 0){
			
			scanf("\n%c", &tmp);
			if(tmp == 'D') dir = dir + 1;
			
			else if(tmp == 'E') dir = dir - 1;

			if(dir == 0) dir = BAIXO;

			if(tmp == 'F'){
				

				if(dir == ESQUERDA){
					if(tab[a][b - 1] != '#'){
						b = b - 1;
						if(tab[a][b] == '*'){
							cont++;
						}
					}
				}

				else if(dir == CIMA){
					if(tab[a - 1][b] != '#'){
						a = a - 1;
						if(tab[a][b] == '*'){
							cont++;
						}
					}
				}
				
				else if(dir == DIREITA){
					if(tab[a][b + 1] != '#'){
						b = b + 1;
						if(tab[a][b] == '*'){
							cont++;
						}
					}

				}

				else if(dir == BAIXO){
					if(tab[a + 1][b] != '#'){
						a = a + 1;
						if(tab[a][b] == '*'){
							cont++;
						}
					}
				}
			}
			n--;
 		}
 		printf("%d\n", cont);
	}
	return 0;
}
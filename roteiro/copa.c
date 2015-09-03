#include <stdio.h>
/*ideia: coloco os times de A a P em um vetor. entao uso ele como uma fila 
comparando sempre os dois primeiros atraves do resultado. quem ganha vai para o topo 
da fila. quem perde sai dela. no final o ganhador é quem esta no topo da fila*/
int main(){

	int  i, b, c, d, topo, ini;
	char a[100];

	for(i=0; i<16; i++){
		a[i] = 65 + i;
	}
	topo = i;

	b = 15;
	ini = 0;
	while(b > 0){

		scanf("%d %d", &c, &d);

		if(c > d){
			a[topo] = a[ini];
		} 
		else{
			a[topo] = a[ini + 1];
		}
		
		if(b > 1) topo ++;

		ini += 2;
		b--;
	}

	printf("%c\n", a[topo]);
	return 0;
}	
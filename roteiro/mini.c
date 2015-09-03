#include <stdio.h>

int main(){

	int n, v[15], a, c, i, ant, atu, cont = 1, menor, maior;

	scanf("%d", &n);

	while(n > 0){
		c = 0;
		ant = 0;
		atu = 0;

		for(i=1; i<14; i++) v[i] = 0;

		for(i=1; i<=5; i++){
			scanf("%d", &a);
			v[a] ++;
		}

		for(i=1; i<=13; i++){

			if(v[i] != 0) c ++;
		}
		printf("c = %d\n", c);

		if(c == 2){//temos uma quadra ou full house

			for(i=1; i<=13; i++){
				if(v[i] == 3){
					printf("Teste %d\n%d\n\n", cont, 180 + i);
					break;
				}
				else if(v[i] == 4){
					printf("Teste %d\n%d\n\n", cont, 140 + i);
					break;
				}
			}
		}	
		
		else if(c == 3){

			for(i=1; i<=13; i++){
				
				if(v[i] == 2){
					if(ant == 0) ant = i;
					
					else atu = i;
					
					continue;
				}
				
				else if(v[i] == 3){
					printf("Teste %d\n%d\n\n", cont, 180 + i);
					break;
				}

				if(atu != 0){
					if(atu > ant){
						printf("Teste %d\n%d\n\n", cont, 3*atu + 2*ant + 20);
					}
					else{
						printf("Teste %d\n%d\n\n", cont, 3*ant + 2*atu + 20);
					}
				}
			}
		}

		else if(c == 4){

			for(i=1; i<=13; i++){

				if(v[i] == 2) printf("Teste %d\n%d\n\n", cont, i);
			}
		}

		else if(c == 5){

			maior = 0;
			menor = 14;
			for(i=1; i<=13; i++){

				if(v[i] != 0){
					atu = i;

					if(atu < menor) menor = atu;

					else if(atu > maior) maior = atu;
				}
			}
			
			if((maior - menor) == 4) printf("Teste %d\n%d\n\n", cont, 200 + menor);

			else printf("Teste %d\n%d\n\n", cont, 0);
		}
		n--;
		cont ++;	
	}
	return 0;
}
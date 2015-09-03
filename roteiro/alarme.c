#include <stdio.h>

int main(){

	int min, m, hora, h, soma;
	
	while(scanf("%d %d %d %d", &hora, &min, &h, &m) && (hora != 0 || min != 0 || h != 0 || m != 0)){
		
		if(hora == h){

			if(min < m){
				soma = min - m;
				printf("%d\n", soma);
			}
			else if(min == m){
				soma = 0;
				printf("%d\n", soma);
			}
			else if(min > m){
				soma = (24 * 60) - (min - m);
				printf("%d\n", soma); 
			}

		}

		else if(hora > h){
			
			if(min < m){
				soma = ((24 - hora) + h) * 60 + (m - min);
				printf("%d\n", soma);
			}
			else if(min == m){
				soma = ((24 - hora) + h) * 60;
				printf("%d\n", soma);
			}
			else if(min > m){
				soma = ((24 - hora) + h) * 60 - (min - m);
				printf("%d\n", soma);
			}


		}

		else if(hora < h){

			if(min < m){
				soma = (h - hora) * 60 + (m - min);
				printf("%d\n", soma);
			}
			else if(min == m){
				soma = (h - hora) * 60;
				printf("%d\n", soma);
			}
			else if(min > m){
				soma = (h - hora) * 60 - (min - m);
				printf("%d\n", soma);
			}
		}
		
	}
	return 0;	
}
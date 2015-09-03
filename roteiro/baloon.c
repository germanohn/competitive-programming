#include <stdio.h>

int main(){

	int n, a, b, c, tmp, aux, easy, hard;

	scanf("%d", &n);

	while(n > 0){

		scanf("%d %d %d", &a, &b, &c);
		aux = a;
		
		while(aux > 0){
			scanf("%d", &tmp);
			if(aux == a) easy = tmp;

			else if(aux == 1) hard = tmp;

			aux --;
		}
		
		if(easy == b && hard == c) printf("BOTH\n");
		else if(easy == b) printf("EASY\n");
		else if(hard == c) printf("HARD\n");
		else if(easy != b && hard != c) printf("OKAY\n");

		n--;
	}
	return 0;
}
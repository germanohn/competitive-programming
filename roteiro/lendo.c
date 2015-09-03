#include <stdio.h>

int main(){

	int a, b, c, pag;
	float d;

	while(scanf("%d", &a) && a != 0){
		
		scanf("%d %d", &b, &c);

		d = (float)(a * b)/(c - a);
		pag = c * d;

		if(pag != 1) printf("%d paginas\n", pag);

		else printf("%d pagina\n", pag);
	}

	return 0;
}	
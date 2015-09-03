#include <stdio.h>

int main(){

	int vitf,ef,sf,vitc,ec,sc,pontosf,pontosc;

	scanf("%d %d %d %d %d %d",&vitc,&ec,&sc,&vitf,&ef,&sf);

	pontosc=3*vitc + ec;
	pontosf=3*vitf + ef;

	if(pontosc>pontosf){
		printf("C\n");
	}

	else if(pontosf>pontosc){
		printf("F\n");
	}

	else if(pontosc==pontosf){
		
		if(sc>sf){
			printf("C\n");
		}

		else if(sf>sc){
			printf("F\n");
		}

		else if(sc==sf){
			printf("=\n");
		}
	}
	return 0;
}
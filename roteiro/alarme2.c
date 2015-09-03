#include <stdio.h>
/*idea é dividir em horaris no mesmo dia e em dias diferentes*/
int main(){

	int H1, H2, M1, M2, tmp;

	while(scanf("%d %d %d %d", &H1, &M1, &H2, &M2) && (H1 != 0 || M1 != 0 || H2 != 0 || M2 != 0)){

		/*dias diferentes*/
		/*veja que tanto em um quanto em outro calculo primeiro a quantidade devida as horas e depois 
		a parte devido aos minutos. a parte devido aos minutos se M2 > M1 entao no if quanto no else
		significa que ira se adicionar M2 - M1 minutos a parte da hora. caso contrario entao esses minutos serao 
		subtraidos da parte das horas pois a parte das horas sempre calcula como se M2 fosse M1. se M2 é menor que 
		M1 entao essa diferença de tempo se perde*/
		if(H2 < H1 || (H2 == H1 && M2 < M1)){
			tmp = 60*(H2 + 24 - H1) + M2 - M1;
			printf("%d\n", tmp);
		}

		/*mesmo dia*/
		else{
			tmp = 60*(H2 - H1) + M2 - M1;
			printf("%d\n", tmp);
		}
	}
	return 0;	
}
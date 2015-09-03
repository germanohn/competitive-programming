/*soluçao bem interessante é:
Primeiro: no c na divisao de dois inteiros sempre se arredonda para baixo.
entao fazendo (ano-1986)/76 teriamos que a conta correta seria(se o ano atual nao fosse uma ano 
em que passa o cometa halley) algum numero com virgula que corresponderia a quantos cometas halley
passaram desde 1986 ate atual.no c aquela razao seria um numero inteiro que corresponderia a exatamente
quantos cometa halley passaram ate o ano atual. entao usamos um truque: somamos 76 a ano-1986 e 
dividimos por 76. isso nos dara o numero de cometas halley que passaram ate o ano atual mais um ou seja
o proximo. entao fazemos 1986 + 76 essa nova razao e teremos o proximo cometa halley depois de atual
ficaria entao*/


#include<stdio.h>

int main(){
	int atual,k;
	scanf("%d",&atual);
	k=(atual-1986+76)/76;
	printf("%d\n",1986 + k*76);
	return 0;
}
	
/*outra soluçao
#include <stdio.h>

int main(){

	int dif,atual,cometa;

	scanf("%d",&atual);

	dif=(atual-1986)%76;

	if(dif==0){
		cometa=atual+76;
	}
	else{
		cometa=atual+(76-dif);
	}
	printf("%d\n",cometa);

	return 0;
}	
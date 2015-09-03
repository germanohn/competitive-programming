/*as fotos serao coladas em duas posiçoes relativas:
uma ao lado da outra ou uma acima da outra, pois devem ficar paralelas 
às bordas do album.Entao no caso de uma ao lado da outra a soma de suas larguras
deve ser menor ou igual a largura do album e a altura de cada uma deve ser menor ou
igual a altura do album. No caso de uma acima da outra a soma de suas altura deve
ser menor ou igual a altura do album e a largura de cada uma deve ser menor ou
igual à do album.
casos especiais:
l1+l2>l ainda assim sera possivel colar se h1+h2 for menor que h e vice-versa*/

/*esse é um problema para trabalhar as condiçoes que garantem casos extremos.
Faz=se a análise por partes:
-Dado que l1+l2<=l o caso extremo de h ocorre colocandoas fotos lado a lado
entao basta que h1<=h && h2<=h que conseguirei colar as fotos.É
claro que se ele quisesse em uma determinada disposiçao entao mudaria as 
condiçoes, mas com nao o fez entao conseguindo colar é o que importa. com a 
a condiçao dos h's acima nao conseguimos dispor de qualquer mas sempre conseguiremos
colar, entao garantimos a condiçao extrema.
-Dado que l1+l2>=l l1<=l e l2<=l entao teremos que ter h1+h2<=h pois o caso extremo sera suportado 
colocando uma acima da outra logo teremos que ter a condiçao anterior de h.
-Dado h1+h2>=h o caso extremo sera para as fotos colocadas lado a lado a teremos
l1+l2<=l.ja entro na primeira condiçao
-Dado h1+h2<=h o caso extremo sera l1<=l e l2<=l*/

#include <stdio.h>

int main(){

	int l,l1,l2,h,h1,h2,cont=0;

	scanf("%d %d %d %d %d %d",&l,&h,&l1,&h1,&l2,&h2);

	if(((l1+l2)<=l && l1<=l && l2<=l && h1<=h && h2<=h)){ 
		printf("S\n");
		return 0;
	}
	if((l1+h2)<=l && l1<=l && h2<=l && h1<=h && l2<=h){
		printf("S\n");
		return 0;
	}
	if((h1+l2)<=l && h1<=l && l2<=l && l1<=h && h2<=h){
		printf("S\n");
		return 0;
	}
	if((h1+h2)<=l && h1<=l && h2<=l && l1<=h && l2<=h){
		printf("S\n");
		return 0;
	}


	if((h1+h2)<=h && h1<=h && h2<=h && l1<=l && l2<=l){
		printf("S\n");
		return 0;
	}
	if((h1+l2)<=h && h1<=h && l2<=h && l1<=l && h2<=l){
		printf("S\n");
		return 0;
	}
	if((l1+h2)<=h && l1<=h && h2<=h && h1<=l && l2<=l){
		printf("S\n");
		return 0;
	}
	if((l1+l2)<=h && l1<=h && l2<=h && h1<=l && h2<=l){
		printf("S\n");
		return 0;
	}

	
	if(cont==0){
		printf("N\n");
		return 0;
	}
}
#include <stdio.h>
#define MAX 1000000

int main(){

	char nome[MAX];
	int num[MAX], i, j;

	for(i = 0; scanf("%c", &nome[i]) != EOF && nome[i] != '\n'; i++){

		if(nome[i] == '-') num[i] = 0;

		else if(nome[i] - 'A' <= 14){
			num[i] = (nome[i] - 'A')/3 + 2;
		}

		else if((nome[i] - 'A') >= 15 && (nome[i] - 'A') <= 18){
			num[i] = 7;
		}

		else if((nome[i] - 'A') >= 19 && (nome[i] - 'A') <= 21){
			num[i] = 8;
		}

		else{
			num[i] = 9;
		}
	}
	j = i;

	for(i = 0; i < j; i++){
		if(num[i] == 0) printf("-");

		else printf("%d", num[i]);
	}
	printf("\n");
	return 0;
}
#include <stdio.h>
#define MAX 100005

void topo( int *top, char pilha[], char x){
	*top = *top + 1;
	pilha[*top] = x;
}

char oposto( char x){
	if(x == ')'){
		return '(';
	}

	else if(x == ']'){
		return '[';
	}

	else if(x == '}'){
		return '{';
	}

	else return '\n';
}

void pop( int *top){
	*top = *top - 1;
}

int main(){
	int n, top=1;
	char pilha[MAX],x;

	scanf("%d",&n);

	while(n != 0){
		top= -1;
		scanf(" %c", &x);
		topo(&top, pilha, x);

		while(scanf("%c", &x) != EOF && x != '\n'){
			
			if(top >= 0 && pilha[top] == oposto( x)){
				pop( &top);
			}	

			else{
				topo(&top, pilha, x);
			}
		}
		if(top == -1) printf("S\n");
		else printf("N\n");

		n--;
	}

	return 0;
}
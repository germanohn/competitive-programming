#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 50

using namespace std;

int main(){

	int n, i, ok;
	char nome[MAX], c, aux;

	scanf("%d", &n);

	while(n--){
		
		ok = 1;
		scanf("%s", nome);
	
		i = 0;		
		while(i < strlen(nome) - 1 && ok == 1){

			if(tolower(nome[i]) >= tolower(nome[i + 1]))
				ok = 0;
			i++;
		}
	

		if(ok) printf("%s: O\n", nome);

		else printf("%s: N\n", nome);	
	}	
}
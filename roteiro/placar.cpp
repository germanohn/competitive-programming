#include <cstdio>
#include <algorithm>
#include <cstring>	

#define MAXN 105

using namespace std;

char nome[MAXN][MAXN];
int n, nota[MAXN], aluno[MAXN];

bool compare(int x, int y){

	if(nota[x] > nota[y]) return false;
	
	if(nota[x] < nota[y]) return true;

	if(strcmp(nome[x], nome[y]) < 0) return false;

	return true;
}

int main(){

	int k = 1;

	while(scanf("%d", &n) != EOF){

		for(int i = 1; i <= n; i++) scanf("%s %d", nome[i], &nota[i]);

		for(int i = 1; i <= n; i++) aluno[i] = i;

		sort(aluno + 1, aluno + n + 1, compare);

		printf("Instancia %d\n%s\n\n", k, nome[aluno[1]]);	

		k++;
	}	
}
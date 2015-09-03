#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 1000100
#define MAXL 30

using namespace std;

struct jogador{

	char nome[30];
	int nota;
};

struct rod{

	char name[30];
};

jogador time[MAXN];
rod team[MAXN][MAXN];


bool compara1(jogador x, jogador y){

	if(strcmp(x.nome, y.nome)<0) return true;

	return false;
}

bool compara2(jogador x, jogador y){

	if(x.nota > y.nota) return true;

	else if(x.nota < y.nota) return false;
}

int main(){

	int n, t, i, j, aux;

	scanf("%d %d", &n, &t);

	i=0;
	aux = n;
	while(aux > 0){

		j=0;
		scanf("%c", &time[i].nome[j]);
		while(time[i].nome[j] != ' '){
			scanf("%c", &time[i].nome[j]);
			j++;
		}	
		scanf("%d", &time[i].nota);
		i++;
	}

	sort(time, time + n, compara2);

	aux = n;
	topo = n;
	while(aux > 0){

		i=0;
		auz = t;
		while(auz > 0 && topo > 0){
			team[i].name = time[topo].nome;
			topo--;
			auz--;
			i++;
		}
		
		while(auz < t && topo > 0){
			team[i].name = time[topo].nome;
			topo--;
			auz++;
			i--;
		}
		aux -= 2*t;
	}	

	for(i=0; i<t; i++){

		//funçao tamanho do vetor
		sort(team, team ,compara1);
	}
}
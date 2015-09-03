#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#define MAX 505

using namespace std;

int v[MAX][2];
int m[MAX][10005];

int n;

int pig(int i, int c){
	
	int r1, r2;

	if(i == n || c < 0) return 10000000;

	if(c == 0) return 0;

	if(m[i][c] != -1) return m[i][c];
	
	r2 = pig(i + 1, c);//retorna o minimo de dinheiro que estaria no porco sem a moeda i
	r1 = v[i][0] + pig(i, c - v[i][1]);//retorna o minimo dinheiro que estaria no porco com a moeda i 
	
	m[i][c] = min(r1, r2);// retorna o valor minimo de dinheiro no porco entre ter ou nao colocado a moeda i

	return m[i][c];
}


int main(){

	int t, e, f, i;

	scanf("%d", &t);

	while(t--){

		scanf("%d %d", &e, &f);

		scanf("%d", &n);
		memset(m, -1, sizeof m);

		for(i = 0; i < n; i++)
			scanf("%d %d", &v[i][0], &v[i][1]);
		
		if(pig(0, f-e) == 10000000)
			printf("This is impossible.\n");	

		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", pig(0, f-e));
	}
}	

#include <cstring>
#include <climits>
#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;

int mx[4] = {0, 0, 1, -1}, my[4] = {1, -1, 0, 0};
int dp[1003][1003], df[1003][1003];
char mapa[1003][1003];
queue<pii> qf;

void showF(int n, int m){
	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= m+1; j++)
			printf("%d ", df[i][j]);
		printf("\n");
	}
}

int bfsp(pii ini, pii fim){
	queue<pii> q;
	q.push(ini);

	while(q.size()){
		pii v = q.front();
		q.pop();
		
		if(v == fim){  return 1;}

		for(int i = 0; i < 4; i++){
			int nxt = dp[v.x+mx[i]][v.y+my[i]];
			if(nxt > dp[v.x][v.y] + 1){
				dp[v.x+mx[i]][v.y+my[i]] = dp[v.x][v.y] + 1;	
				if(dp[v.x+mx[i]][v.y+my[i]] < df[v.x+mx[i]][v.y+my[i]]){
					q.push(mp(v.x+mx[i], v.y+my[i]));
				}
			}

		}
	}

	return INT_MAX;
}

void bfsf(){
	while(qf.size()){
		pii v = qf.front();
		qf.pop();
		
		for(int i = 0; i < 4; i++){
			int nxt = df[v.x+mx[i]][v.y+my[i]];
			if(nxt > df[v.x][v.y]){
				df[v.x+mx[i]][v.y+my[i]] = df[v.x][v.y] + 1;		
				qf.push(mp(v.x+mx[i], v.y+my[i]));
			}
		}
	}
}

int main(){
	int t, n, m;
	
	ios::sync_with_stdio(false);

	cin >> t;
	while(t--){
		pii ini, fim; 
		
		memset(df, -1, sizeof df);
		memset(dp, -1, sizeof dp);
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> mapa[i][j];
				if(mapa[i][j] != '#'){
					dp[i][j] = INT_MAX;
					df[i][j] = INT_MAX;
				}
				if(mapa[i][j] == 'S'){
					dp[i][j] = 0;
					ini.first = i;
					ini.second = j;			
				}

				if(mapa[i][j] == 'E'){
					fim.first = i;
					fim.second = j;
				}
			}
		}

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(mapa[i][j] == 'F'){
					df[i][j] = 0;
					qf.push(mp(i,j));
				}
			}
		}

		bfsf();
		bool dead = false;
	if(bfsp(ini, fim) == INT_MAX) dead = true;

		if(dead) printf("N\n");
		else printf("Y\n");

	}
		
}


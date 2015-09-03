#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;

vector<pii> adj[30004];
int seen[30004];

int solve(int ini){
	set<pii> s;
	int minCost = 0;
	s.insert(make_pair(0, ini));

	while(s.size()){
		int x = s.begin()-> second;
		int w = s.begin()-> first;

		s.erase(s.begin());

		if(seen[x]) continue;

		minCost += w;
		seen[x] = true;

		for(int i = 0; i < adj[x].size(); i++){
			int y = adj[x][i].second;
			if(!seen[y])
				s.insert(adj[x][i]);
		}
	}

	return minCost;
}

int main(){
	int t, n, m, q, a, b, c;

	scanf("%d", &t);
	while(t--){
		memset(seen, 0, sizeof seen);
		scanf("%d %d %d", &n, &m, &q);
		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(make_pair(c, b));
			adj[b].push_back(make_pair(c,a));
		}

		for(int i = 0; i < q; i++){
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(make_pair(c,b));
			adj[b].push_back(make_pair(c,a));
			printf("%d\n", solve(1));
		}
	}
}

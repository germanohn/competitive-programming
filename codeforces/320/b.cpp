#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n, turn;
int seen[MAX];
vector<pii> v;
vector<int> adj[MAX];

int dfs(int a, int b) {
    seen[a] = turn;
    if (a == b) return true;
    for (auto nx : adj[a]) {
        if (seen[nx] < turn) 
            if (dfs(nx, b))
                return true;
    }
    return false;
}

int main () {
    scanf(" %d", &n);
    turn = 1;
    for (int i = 0; i < n; i++) {
        int t, a, b;
        scanf(" %d %d %d", &t, &a, &b);
        if (t == 1) {
            for (int j = 0; j < v.size(); j++) {
                pii x = v[j];
                if ((a > x.ff && a < x.ss) || (b > x.ff && b < x.ss)) 
                    adj[v.size()].pb(j);
                if ((x.ff > a && x.ff < b) || (x.ss > a && x.ss < b))
                    adj[j].pb(v.size());
            }    
            v.pb(pii(a, b));
        } else {
            a--, b--;
            if (dfs(a, b)) printf("YES\n");
            else printf("NO\n");
            turn++;
        }
    }
}


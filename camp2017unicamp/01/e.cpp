#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 201;
int l[N][N], n, k, visi[N][N], r[N];
set<int> ans;

void dfs(int v, int e) {
    if(visi[v][e]) return;
    visi[v][e] = 1;
    if(e == k) ans.insert(v);
    else {
        for(int w = 0; w < n; w++)
            if(l[v][w] == r[e])
                dfs(w, e+1);
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &l[i][j]);

    scanf("%d", &k);
    for(int i = 0; i < k; i++) scanf("%d", r+i);
    dfs(0,0);
    printf("%d\n", ans.size());
    for(int v : ans) printf("%d ", v+1);
    putchar('\n');
}
    

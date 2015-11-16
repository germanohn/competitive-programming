#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, f;
int gr[MAX], sum[MAX], pai[MAX];
bool forb[MAX], fr[MAX];
vector<pii> adj[MAX];

int dfs (int no, int pai) {
    if (gr[no] == 1 && no != 1) return 0;
    sum[no] = 0;
    for (int i = 0; i < adj[no].size (); i++) {
        pii nx = adj[no][i];
        if (nx.ff != pai && !forb[nx.ff]) {
            sum[no] += nx.ss + dfs (nx.ff, no);
        }
    }
    return sum[no];
}

void del (int no) {
    forb[no] = true;
    gr[pai[no]]--;
    if (gr[pai[no]] == 1 && pai[no] != 1 && !fr[pai[no]]) {
        del (pai[no]);
    }

}

int solve (int no, int pai) {
    if (gr[no] == 1 && no != 1) return 0; 
    int ans = INT_MAX;
    for (int i = 0; i < adj[no].size (); i++) {
        int node = adj[no][i].ff;
        if (forb[node] || node == pai) continue;
        ans = min (ans, sum[no] - sum[node] -adj[no][i].ss + solve (node, no));
    }
    return ans;
}

int main () {
    while (scanf ("%d %d", &n, &f) != EOF) {
        for (int i = 0; i <= n; i++) {
            gr[i] = pai[i] = fr[i] = sum[i] = forb[i] = 0, adj[i].clear ();
        }
        memset (gr, 0, sizeof (gr));
        int a, b, c;
        for (int i = 0; i < n-1; i++) {
            scanf ("%d %d %d", &a, &b, &c);
            adj[a].pb (mp (b, c));
            adj[b].pb (mp (a, c));
            gr[a]++;
            gr[b]++;
            pai[b] = a;
        } 
        for (int i = 1; i <= f; i++) {
            scanf ("%d", &a);
            fr[a] = true;
        }
        for (int i = 2; i <= n; i++) {
            if (gr[i] == 1 && !fr[i] && !forb[i]) del (i);
        } 
        dfs (1, -1);
        printf ("%d\n", solve (1, -1));
    }
}

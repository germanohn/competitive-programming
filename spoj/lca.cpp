#include <bits/stdc++.h>
#define pb push_back
#define debug(args...) fprintf (stderr, args)
#define MAX 16005
using namespace std;

int seg[MAX];
int height[MAX], idx;//altura do no na arvore
int tree[MAX];//vetor da arvore planificada
int last[MAX];//ultima ocorrencia o i-esimo vertice do vetor na arvore
bool vis[MAX];
vector<int> adj[MAX];

void dfs (int n, int h) {
    vis[n] = true;
    tree[idx] = n, height[idx] = h, last[n] = idx;
    idx++;
    for (int i = 0; i < adj[n].size (); i++) {
        int son = adj[n][i];
        if (!vis[son]) {
            dfs (son, h+1);
            tree[idx] = n, height[idx] = h, last[n] = idx;
            idx++;
        }
    }
}

void update (int l, int r, int n, int v, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[n] = v;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*n, v, ind);
    update (m+1, r, 2*n+1, v, ind);
    if (height[last[seg[2*n]]] < height[last[seg[2*n+1]]]) seg[n] = seg[2*n];
    else seg[n] = seg[2*n+1];
}

int query (int l, int r, int n, int a, int b) {
    if (l >= a && r <= b) return seg[n];
    if (a > r || b < l) return INT_MAX;
    int m = (l+r)/2;
    int x = query (l, m, 2*n, a, b), y = query (m+1, r, 2*n+1, a, b);
    if (x == INT_MAX) return y;
    if (y == INT_MAX) return x;
    if (height[last[y]] < height[last[x]]) {
        return y;
    }
    return x;
}

int main () {
    int t, cont = 1;
    scanf ("%d", &t);
    while (t--) {
        int n, quant, a, b, q;
        idx = 0;
        scanf ("%d", &n);
        for (int i = 0; i < MAX; i++)
            vis[i] = false, adj[i].clear (), height[i] = 0, last[i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &quant);
            while (quant--) {
                int son;
                scanf ("%d", &son);
                adj[i].pb (son), adj[son].pb (i);
            }
        }
        dfs (1, 0);
        for (int i = 0; i < idx; i++) update (0, idx-1, 1, tree[i], i);
        scanf ("%d", &q);
        printf ("Case %d\n", cont++);
        while (q--) {
            scanf ("%d %d", &a, &b);
            a = last[a], b = last[b];
            if (a > b) swap (a, b);
            printf ("%d\n", query (0, idx-1, 1, a, b));
        }
    }
}

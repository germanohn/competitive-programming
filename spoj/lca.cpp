#include <bits/stdc++.h>
#define pb push_back
#define debug(args...) fprintf (stderr, args)
#define MAX 4005
using namespace std;

int seg[4*MAX];
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
    else if (l == r) {
        seg[n] = v;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*n, v, ind);
    update (m+1, r, 2*n+1, v, ind);
    printf ("UPDATE height %d %d\n", height[last[seg[2*n]]], height[last[seg[2*n+1]]]);
    if (height[last[seg[2*n]]] < height[last[seg[2*n+1]]]) seg[n] = seg[2*n];
    else seg[n] = seg[2*n+1];
}

int query (int l, int r, int n, int a, int b) {
    if (a > r || b < l) return INT_MAX;
    if (l >= a && r <= b) return seg[n];
    int m = (l+r)/2;
    int x = query (l, m, 2*n, a, b), y = query (m+1, r, 2*n+1, a, b);
    if (x == INT_MAX) return y;
    printf ("depois\n");
    if (y == INT_MAX) return x;
    printf ("QUERY height %d %d last[y] %d last[x] %d\n", height[last[y]], height[last[x]], last[y], last[x]);
    if (height[last[y]-1] < height[last[x]-1]) {
        return y;
    }
    return x; 
}   

int main () {
    int t, cont = 1;
    scanf ("%d", &t);
    while (t--) {
        int n, quant, a, b, q;
        scanf ("%d", &n);
        for (int i = 0; i < 4*n; i++) 
            vis[i] = false, adj[i].clear ();
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
        printf ("tree   ");
        for (int i = 0; i <= 4*n; i++) printf ("%d ", tree[i]);
        printf ("\nheight ");
        for (int i = 0; i <= 4*n; i++) printf ("%d ", height[i]);
        printf ("\nlast   ");
        for (int i = 0; i <= 4*n; i++) printf ("%d ", last[i]);
        printf ("\n\n");
        scanf ("%d", &q);
        for (int i = 0; i <= 8*n; i++) printf ("%d ", seg[i]);
        printf ("\n");
        printf ("Case %d\n", cont++);
        while (q--) {
            scanf ("%d %d", &a, &b);
            printf ("%d\n", query (0, n-1, 1, last[a]-1, last[b]));
        }  
    }
}

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m, q;
int tear[MAX], pai[MAX], size[MAX], ans[MAX], forbid[MAX];
pii edge[MAX];

int find (int a) {
    if (a == pai[a]) return a;
    return pai[a] = find (pai[a]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (size[a] < size[b]) swap (a, b);
    size[a] += size[b];
    pai[b] = pai[a];
    return true;
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        pai[i] = i;
        size[i] = 1;
    }
    int a, b;
    // coloca as arestas existentes
    for (int i = 1; i <= m; i++) {
        scanf ("%d %d", &a, &b);
        edge[i] = pii (a, b);
    }
    scanf ("%d", &q);
    // recebe as arestas que serao cortadas 
    for (int i = 0; i < q; i++) {
        scanf ("%d", &tear[i]);
        forbid[tear[i]] = 1;
    }
    // monta o grafo ja tirando as arestas que serao cortadas
    for (int i = 1; i <= m; i++) {
        if (!forbid[i]) {
            int a = edge[i].ff, b = edge[i].ss;
            join (a, b);
        }    
    }
    // vou ver quantos componentes tenho no comeco
    int comp = 0;
    for (int i = 1; i <= n; i++) {
        if (pai[i] == i) 
            comp++;
    }
    ans[q-1] = comp;
    for (int i = q-1; i >= 0; i--) {
        int a = edge[tear[i]].ff, b = edge[tear[i]].ss;
        if (join (a, b)) {
            ans[i-1] = ans[i]-1;  
        }
        else ans[i-1] = ans[i]; 
    }
    for (int i = 0; i < q; i++)
        printf ("%d ", ans[i]);
    printf ("\n");
}







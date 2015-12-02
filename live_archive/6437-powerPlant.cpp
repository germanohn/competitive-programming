/* Ideia: faz o kruskal normal mas quando no join, so unira dois 
// conjuntos se pelo menos um nao tiver ligado a powerplant ainda.*/
#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

const int MAX = 205;

int t, n, m, k;
int pai[MAX], peso[MAX];
bool f[MAX];

int find (int x) {
    if (x == pai[x]) return x;
    return pai[x] = find (pai[x]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b || (f[a] && f[b])) return false;
    if (peso[a] < peso[b]) swap (a, b);
    if (f[a] || f[b]) {
        f[a] = true;
        f[b] = true;
    }
    pai[b] = a;
    peso[a] += peso[b];
    return true;
}

int main () {
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        priority_queue<pair<int, pii> > pq;
        scanf ("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
            f[i] = false;
        }
        int aux;
        for (int i = 1; i <= k; i++) {
            scanf ("%d", &aux);
            f[aux] = true;
        } 
        int a, b, w;
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &a, &b, &w);
            if (a > b) swap (a, b);
            pq.push (mp (-w, mp (a, b)));
        }
        int ans = 0, custo;
        while (!pq.empty ()) {
            pii nx = pq.top ().ss;
            custo = -pq.top ().ff;
            pq.pop ();
            if (join (nx.ff, nx.ss)) 
                ans += custo;
        }
        printf ("Case #%d: %d\n", cont++, ans);
    }
}

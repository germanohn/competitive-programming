#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int n, m, pai[MAX], peso[MAX];

int find (int x) {
    if (x == pai[x]) return x;
    return pai[x] = find (pai[x]);
}

void join (int x, int y) {
    x = find (x), y = find (y);
    if (x == y) return;
    if (x < y) swap (x, y);
    pai[y] = pai[x];
    peso[x] += peso[y];
}

int main () {
    int cont = 1;
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        priority_queue<pair<int, pii> > p;
        int w, a, b;
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &a, &b, &w);
            if (a > b) swap (a, b);
            p.push (mp (-w, pii (a, b)));
        }
        vector<pii> ans;
        while (!p.empty ()) {
            pii nx = p.top ().ss;
            p.pop ();
            if (find (nx.ff) != find (nx.ss)) {
                join (nx.ff, nx.ss);
                ans.pb (pii (nx.ff, nx.ss));
            }
        }
        printf ("Teste %d\n", cont++);
        for (int i = 0; i < ans.size (); i++) {
            printf ("%d %d\n", ans[i].ff, ans[i].ss);
        }
        printf ("\n");
    }
}

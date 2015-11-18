#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 1005;

int n, m, pai[MAX], peso[MAX], vp[MAX]; 
ll ans;
vector<pair<int, pii> > v;

int find (int x) {
    if (pai[x] == x) return x;
    return pai[x] = find (pai[x]);
}

void join (int x, int y) {
    x = find (x), y = find (y);
    if (x == y) return;
    if (x < y) swap (x, y);
    pai[y] = pai[x];
    peso[x] += peso[y];
}

vector<int> rta;
int aux[] = {1235,8977,10923};
int tmp[20000];

void countingsort (vector<pair<int, pii> > a, int tam) {
    for (int i = 0; i < tam; i++) {
        vp[tmp[v[i].ff]]++;
    }   
    for (int i = 0; i < 3; i++) {
        while (vp[i]--) {
            rta.pb (aux[i]);
        } 
    }

}

int main () {
    int cont = 1;
    tmp[1235] = 0, tmp[8977] = 1, tmp[10923] = 2;
    while (scanf ("%d %d", &n, &m) != EOF) {
        v.clear ();
        rta.clear ();
        int w, a, b;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &a, &b, &w);
            v.pb (mp (w, pii (a, b)));
        }  
        vp[0] = 0, vp[1] = 0, vp[2] = 0;
        countingsort (v, v.size ());
        for (int i = 0; i < v.size (); i++) {
            pii nx = v[i].ss;
            int p = v[i].ff;
            if (find (nx.ff) != find (nx.ss)) {
                join (nx.ff, nx.ss);
                ans += p;
            }
        }
        printf ("Instancia %d\n%lld\n\n", cont++, ans);
    }
}

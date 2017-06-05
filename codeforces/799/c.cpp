#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, c, d;
pii mx[2][N];
vector<pii> coin, diam;
vector<int> aux;

bool cmp_coin(int a, int b) {
    return coin[a].ff < coin[b].ff;
}

bool cmp_diam(int a, int b) {
    return diam[a].ff < diam[b].ff;
}

int main () {
    scanf(" %d %d %d", &n, &c, &d);
    for (int i = 0; i < n; i++) {
        int be, co;
        char c;
        scanf(" %d %d %c", &be, &co, &c);
        if (c == 'C') {
            coin.pb(pii(be, co));
        } else {
            diam.pb(pii(be, co));
        }
    }

    sort(coin.begin(), coin.end());
    sort(diam.begin(), diam.end());

    // maior sozinho
    int best_c1 = 0;
    for (int i = 0; i < coin.size(); i++) {
        if (coin[i].ff > best_c1 && coin[i].ss <= c) {
            best_c1 = coin[i].ff;
        }
    }
    int best_d1 = 0;
    for (int i = 0; i < diam.size(); i++) {
        if (diam[i].ff > best_d1 && diam[i].ss <= d) {
            best_d1 = diam[i].ff;
        }
    }

    for (int i = 0; i < coin.size(); i++) {
        int cost = coin[i].ss;
        pii cur = mx[0][cost];
        if (coin[i].ff > coin[cur.ff].ff) {
            cur.ss = cur.ff;
            cur.ff = i;
        } else if (coin[i].ff > coin[cur.ss].ff) {
            cur.ss = i;
        }
        mx[0][cost] = cur;
    }
    for (int i = 1; i < N; i++) {
        aux.clear();
        aux.pb(mx[0][i].ff);
        aux.pb(mx[0][i].ss);
        aux.pb(mx[0][i - 1].ff);
        aux.pb(mx[0][i - 1].ss);
        if (coin.size())
            sort(aux.begin(), aux.end(), cmp_coin);
        mx[0][i] = pii(aux[3], aux[2]);
    }

    int best_c2 = 0;
    for (int i = 0; i < coin.size(); i++) {
        int rest = c - coin[i].ss;
        int aux = coin[i].ff;
        if (rest <= 0 || coin[mx[0][rest].ff].ss > rest) 
            continue;
        if (mx[0][rest].ff != i) 
            best_c2 = max(best_c2, aux + coin[mx[0][rest].ff].ff);
        else if (mx[0][rest].ss != i) 
            best_c2 = max(best_c2, aux + coin[mx[0][rest].ss].ff);
    }

    for (int i = 0; i < diam.size(); i++) {
        int cost = diam[i].ss;
        pii cur = mx[1][cost];
        if (diam[i].ff > diam[cur.ff].ff) {
            cur.ss = cur.ff;
            cur.ff = i;
        } else if (diam[i].ff > diam[cur.ss].ff) {
            cur.ss = i;
        }
        mx[1][cost] = cur;
    }
    for (int i = 1; i < N; i++) {
        aux.clear();
        aux.pb(mx[1][i].ff);
        aux.pb(mx[1][i].ss);
        aux.pb(mx[1][i - 1].ff);
        aux.pb(mx[1][i - 1].ss);
        if (diam.size())
            sort(aux.begin(), aux.end(), cmp_diam);
        mx[1][i] = pii(aux[3], aux[2]);
    }

    int best_d2 = 0;
    for (int i = 0; i < diam.size(); i++) {
        int rest = d - diam[i].ss;
        int aux = diam[i].ff;
        if (rest <= 0 || diam[mx[1][rest].ff].ss > rest) 
            continue;
        if (mx[1][rest].ff != i) 
            best_d2 = max(best_d2, aux + diam[mx[1][rest].ff].ff);
        else if (mx[1][rest].ss != i) 
            best_d2 = max(best_d2, aux + diam[mx[1][rest].ss].ff);
    }

    int ans = max(best_c2, best_d2);
    if (best_c1 != 0 && best_d1 != 0)
        ans = max(ans, best_c1 + best_d1);
    printf("%d\n", ans);    
}


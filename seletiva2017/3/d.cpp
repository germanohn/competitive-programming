#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 500;
const int inf = 1e9;

int t, n, cont;
int r[N], c[N], d[N];
int st[N], to[N], w[N]; 

void add(int u, int v, int sz) {
    st[cont] = u; to[cont] = v; w[cont] = sz;
    cont++;
}

bool bellman_ford(int k) {
    for (int i = 0; i < 24; i++) {
        d[i] = inf;
        add(24, i, 0);
    }
    d[24] = 0;

    for (int i = 0; i < 25; i++) 
        for (int j = 0; j < cont; j++) 
            d[to[j]] = min(d[to[j]], d[st[j]] + w[j]);

    for (int i = 0; i < cont; i++) { 
        if (d[to[i]] > d[st[i]] + w[i]) {
            printf("d[%d] %d w[%d] %d d[%d] %d\n", st[i], d[st[i]], i, w[i], to[i], d[to[i]]);
            return false;
        }
    }
    
    return true;
}

void build(int k) {
    for (int i = 0; i <= 7; i++) 
        add(i, 24 - 8 + i, k - r[i]);
    for (int i = 8; i < 24; i++) 
        add(i, i - 8, -r[i]);

    /*add(25, 0, c[0]);
    for (int i = 1; i <= 23; i++) { 
        add(i - 1, i, c[i]);
    }*/

    add(25, 23, k);
    add(23, 25, -k);
}

int main () {
    scanf(" %d", &t);
    while (t--) {
        for (int i = 0; i < 24; i++) 
            scanf(" %d", &r[i]);
        scanf(" %d", &n);
        for (int i = 0; i < 24; i++)
            c[i] = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf(" %d", &a);
            c[a]++;
        }
        for (int i = 0; i < 24; i++) 
            printf("%d ", c[i]);
        printf("\n");

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            build(mid);
            printf("::\nlo %d mid %d hi %d\n", lo, mid, hi);
            if (bellman_ford(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        printf("%d\n", lo);
    }
}


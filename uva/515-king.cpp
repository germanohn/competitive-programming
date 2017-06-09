#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 305;
const int inf = 1e9;

int n, m, edges;
int st[N], to[N];
ll w[N], d[N];

bool bellman_ford() {
    d[n + 1] = 0;
    for (int i = 0; i <= n; i++) {
        d[i] = inf;
        st[edges] = n + 1; to[edges] = i; w[edges] = 0;
        edges++;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < edges; j++) {
            if (d[to[j]] > d[st[j]] + w[j]) 
                d[to[j]] = d[st[j]] + w[j];
        }
    }

    for (int i = 0; i < edges; i++) {
        if (d[to[i]] > d[st[i]] + w[i])
            return false;
    }

    return true;
}

int main () {
    while (scanf(" %d", &n)) {
        if (n == 0) break;
        edges = 0;
        scanf(" %d", &m);
        for (int i = 0; i < m; i++) {
            int si, ni;
            ll ki;
            char oi[4];
            scanf(" %d %d %s %lld", &si, &ni, oi, &ki);
            if (oi[0] == 'l') {
                st[edges] = si - 1; to[edges] = si + ni; w[edges] = ki - 1;
            } else {
                st[edges] = si + ni; to[edges] = si - 1; w[edges] = -ki - 1;
            }
            edges++;
        }

        if (bellman_ford()) printf("lamentable kingdom\n");
        else printf("successful conspiracy\n");
    }
}


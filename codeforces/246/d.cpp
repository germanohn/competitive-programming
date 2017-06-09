#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, m;
int c[N];
set<int> q[N];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &c[i]);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        if (c[a] != c[b]) {
            q[c[a]].insert(c[b]);
            q[c[b]].insert(c[a]);
        }
    }

    int _max = -1, ans = N;
    for (int i = 0; i < n; i++) {
        int aux = q[c[i]].size();
        if (aux > _max || (aux == _max && c[i] < ans)) 
            _max = aux, ans = c[i];
    }
    printf("%d\n", ans);
}


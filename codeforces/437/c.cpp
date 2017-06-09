#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n, m;
int cost[MAX];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &cost[i]);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        ans += min(cost[a], cost[b]);
    }
    printf("%lld\n", ans);
}


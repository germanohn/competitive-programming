#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const int MOD = 1e9 + 7;

int n, m;
char book[N][N];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf(" %c", &book[i][j]);
    ll ans = 1;
    for (int j = 0; j < m; j++) {
        set<int> dif;
        for (int i = 0; i < n; i++) 
            dif.insert(book[i][j]);
        ans = (ans * (ll) dif.size()) % MOD;
    }
    printf("%lld\n", ans);
}


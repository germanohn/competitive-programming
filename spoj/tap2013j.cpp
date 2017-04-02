#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int t, n;
int me[N][N][2];

int dp(int sz, int lo, int f) {
    if (sz < lo) return 0;
    if (sz == lo) return f;
    if (me[sz][lo][f] != -1) return me[sz][lo][f];

    return me[sz][lo][f] = (dp(sz, lo + 1, f) + dp(sz - lo, lo, !f)) % MOD;
}

int main () {
    scanf(" %d", &t);
    memset(me, -1, sizeof me);
    while (t--) {
        scanf(" %d", &n);
        bool f;
        if ((n - 1) % 2 == 1) f = 1;
        else f = 0;
        printf("%d\n", dp(n, 1, f));
    }
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e3 + 5;

int n;
int a[N], fst[N], ult[N], me[N];
int seen[N];
int seg[N][N]; // -1 se não der, senão é o xor do segmento

int dp(int i) {
    if (i == n) return 0;
    if (me[i] != -1) return me[i];

    int ans = 0;
    for (int j = i; j < n; j++) 
        ans = max(ans, max(dp(j + 1), seg[i][j] + dp(j + 1)));

    return me[i] = ans;
}

int main () {
    scanf(" %d", &n);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
        ult[a[i]] = i;
        fst[a[i]] = n;
    }

    for (int i = 0; i < n; i++) {
        if (fst[a[i]] == n)
            fst[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int l = fst[a[i]];
        int r = ult[a[i]];
        int _xor = 0;
        for (int j = 1; j < N; j++) 
            seen[j] = 0;
        for (int j = i; j < n; j++) {
            if (!seen[a[j]])
                _xor ^= a[j];
            seen[a[j]] = true;
            r = max(r, ult[a[j]]);
            l = min(l, fst[a[j]]);
            if (l >= i && r == j) {
                seg[i][j] = _xor;
            } else {
                seg[i][j] = 0;
            }
        }
    }

    printf("%d\n", dp(0));
}


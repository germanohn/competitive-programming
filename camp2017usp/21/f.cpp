#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, k;
int f[N], acc[N], best[N];

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &f[i]);
        acc[i + 1] = f[i] + acc[i];
    }

    k = min(k, n);
    int cur = acc[n] - acc[n - k + 1];
    for (int i = n - k; i >= 0; i--) {
        cur += f[i] - f[i + k];
        if (cur > best[i + 1]) {
            best[i] = cur;
        } else {
            best[i] = best[i + 1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n - k + 1; i++) 
        ans = max(ans, acc[i + k] - acc[i] + best[i + k]);

    printf("%d\n", ans);
}


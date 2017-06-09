#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int n, m;
int f[MAX], g[MAX], h[MAX];

int main() {
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &f[i]);
    }
    int m = 1;
    for (int i = 1; i <= n; i++) {
        g[i] = g[f[i]];
        if (!g[i]) g[i] = g[f[i]] = m++;
    }
    m--;
    bool ans = true;
    for (int i = 1; ans && i <= n; i++) {
        if (h[g[i]] && h[g[i]] != f[i]) {
            ans = false;
            break;
        }
        h[g[i]] = f[i];
    }
    if (!ans) 
        printf("-1\n");
    else {
        printf("%d\n", m);
        for (int i = 1; i <= n; i++) 
            printf("%d ", g[i]);
        printf("\n");
        for (int i = 1; i <= m; i++) 
            printf("%d ", h[i]);
        printf("\n");
    }
}

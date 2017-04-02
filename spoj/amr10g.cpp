#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
const int inf = 1e9 + 5;

int t, n, k;
int v[N];

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &n, &k);
        for (int i = 0; i < n; i++) 
            scanf(" %d", &v[i]);
        sort(v, v + n);

        int ans = inf;
        for (int i = 0; i + k - 1 < n; i++) {
            ans = min(ans, v[i + k - 1] - v[i]);
        }
        printf("%d\n", ans);
    }
}


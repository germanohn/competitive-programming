#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e2 + 5;
const int inf = 1e5;

int n, m, k;
int v[N];

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    m--;
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    int ans = inf, aux = -1;
    for (int i = 0; i < m; i++) {
        if (v[i] != 0 && v[i] <= k)
            aux = i;
    }
    if (aux != -1) 
        ans = min(ans, (m - aux) * 10);
    aux = -1;
    for (int i = n - 1; i > m; i--) {
        if (v[i] != 0 && v[i] <= k)
            aux = i;
    }
    if (aux != -1) 
        ans = min(ans, (aux - m) * 10);

    printf("%d\n", ans);
}


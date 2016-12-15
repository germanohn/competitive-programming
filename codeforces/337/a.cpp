#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int v[55];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + m);
    int ans = INT_MAX;
    for (int i = 0; i <= m - n; i++) 
        ans = min(ans, v[n + i - 1] - v[i]);
    printf("%d\n", ans);
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2005;
const int inf = 2e9;

int n, d;
int p[N];
int sum[N];
int me[N][25];

int round(int x) {
    int r = x % 10; 
    if (r >= 5) x = x - r + 10;
    else x -= r;
    return x;
}

int dp(int i, int k) {
    if (i == n) return 0;
    if (me[i][k] != -1) return me[i][k];

    int ans = inf;
    if (!k) {
        ans = round(sum[n] - sum[i]);
    } else {
        for (int j = i; j < n; j++) {
            int aux = sum[j + 1] - sum[i] + dp(j + 1, k - 1);    
            aux = round(aux);
            ans = min(ans, aux);
        }
    }

    return me[i][k] = ans;
}

int main () {
    scanf(" %d %d", &n, &d);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &p[i]);
        sum[i + 1] = p[i] + sum[i];
    }

    printf("%d\n", dp(0, d));
}


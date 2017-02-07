#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 500001;

int n, v[N], f[N], p[N];
ll dp[2][N];

int main () {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", v+i);
        f[v[i]]++;
    }
    sort(v, v+n);
    n = unique(v, v+n) - v;

    for(int i = 2; i * i < N; i++) {
        if(p[i]) continue;
        for(int j = i*i; j < N; j += i)
            p[j] = 1;
    }

    for(int s = 2; s < N; s++) dp[n&1][s] = !p[s];

    for(int i = n-1; i >= 0; i--)
        for(int s = 0; s < N; s++) {
            dp[i&1][s] = 0;
            for(int j = 0; j <= f[v[i]]; j++)
                dp[i&1][s] += dp[!(i&1)][s+j*v[i]];
        }
    printf("%lld\n", dp[0][0]);
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
ll sum[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        ll a;
        scanf(" %lld", &a);
        sum[i + 1] = a;
    }

    for (int i = 1; i <= n; i++) 
        sum[i] += sum[i - 1];

    ll ans = 1;
    for (int i = 1; i < n; i++) {
        ans = max(ans, sum[i] * (sum[n] - sum[i]));
    }

    printf("%lld\n", ans);
}


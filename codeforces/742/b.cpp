#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, x;
ll freq[N];

int main () {
    scanf(" %d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        freq[a]++;
    }
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        int a = i ^ x;
        if (a > 1e5 || a < i)
            continue;
        if (x) ans += (freq[i] * freq[a]);
        else ans += ((freq[i] * (freq[i] - 1ll)) / 2);
    }
    printf("%lld\n", ans);
}


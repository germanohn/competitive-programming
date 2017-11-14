#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int n;
ll c[N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &c[i]);

    int cur = c[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (c[i] > cur) {
            c[i] = 0;
        } else {
            cur = c[i];
        }
    }

    int pos = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (ll(i - pos) * c[i]);    
        if (c[i]) pos = i;
    }

    printf("%lld\n", ans);
}


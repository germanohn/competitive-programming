#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;

int n;
int p[N];
bool seen[N];

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &p[i]);

    bool ok = true;
    ll ans = 1;
    for (int i = 0; ok && i < n; i++) {
        if (seen[i]) 
            continue;

        int cur = i, sz = 0;
        while (!seen[cur]) {
            seen[cur] = true;
            cur = p[cur] - 1;
            sz++;
        }

        if (cur != i) 
            ok = false;
        else {
            if (sz % 2 == 0) ans = lcm(ans, sz / 2);
            else ans = lcm(ans, sz);
        }
    }
    
    if (ok) printf("%lld\n", ans);
    else printf("-1\n");
}

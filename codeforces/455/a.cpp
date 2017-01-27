#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
ll v[MAX], freq[MAX];
ll me[MAX];

ll dp(int i) {
    if (i == n) return 0;
    if (me[i] != -1) return me[i];
    return me[i] = max(v[i] * freq[v[i]] + dp(i + freq[v[i]] + freq[v[i] + 1]),
                       dp(i + freq[v[i]]));
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &v[i]);
        freq[v[i]]++;
    }
    sort(v, v + n);
    printf("%lld\n", dp(0));
}

/* Solucao com dp iterativa
const int MAX = 100005;

int n;
ll v[MAX], freq[MAX];
ll ans[MAX];

int main () {
    scanf(" %d", &n);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &v[i]);
        freq[v[i]]++;
        mx = max(mx, v[i]);
    }
    ans[0] = 0, ans[1] = freq[1];
    for (int i = 2; i <= mx; i++) 
        ans[i] = max(ans[i - 1], ans[i - 2] + freq[i] * i);
    printf("%lld\n", ans[mx]);
}
*/

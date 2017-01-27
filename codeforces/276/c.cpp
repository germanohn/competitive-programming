#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n, q;
ll v[MAX], freq[MAX];

int main () {
    scanf(" %d %d", &n, &q);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    while (q--) {
        int l, r;
        scanf(" %d %d", &l, &r);
        l--, r--;
        freq[l]++, freq[r + 1]--;
    }
    int acc = 0;
    for (int i = 0; i < n; i++) {
        int up = freq[i];
        freq[i] += acc;
        acc += up;
    }
    sort(freq, freq + n, greater<int>());
    sort(v, v + n, greater<int>());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!freq[i]) 
            break;
        ans += freq[i] * v[i]; 
    }
    printf("%lld\n", ans);
}


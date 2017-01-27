#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

ll n, m, k, x, y;
ll t[MAX][MAX];

int main () {
    scanf(" %lld %lld %lld %lld %lld", &n, &m, &k, &x, &y);
    ll q;
    if (n == 1) q = k / m;
    else q = k / ((n + (n - 2)) * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && i < n - 1) t[i][j] += (2 * q);
            else t[i][j] += q;
        }
    }
    if (n == 1) k -= q * m;
    else k -= (q * ((n + (n - 2)) * m));
    for (int i = 0; k && i < n; i++) {
        for (int j = 0; k && j < m; j++) {
            t[i][j]++;
            k--;
        }
    }
    for (int i = n - 2; k && i >= 0; i--) {
        for (int j = 0; k && j < m; j++) {
            t[i][j]++;
            k--;
        }
    }
    ll ans_mi, ans_mx;
    ans_mi = ans_mx = t[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans_mi = min(ans_mi, t[i][j]);
            ans_mx = max(ans_mx, t[i][j]);
        }
    }
    printf("%lld %lld %lld\n", ans_mx, ans_mi, t[x - 1][y - 1]);
}


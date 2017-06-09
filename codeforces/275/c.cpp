#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
ll k;
ll v[N];
bool seen[N];

int main () {
    scanf(" %d %lld", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf(" %lld", &v[i]);
    if (k == 1) {
        printf("%d\n", n);
        return 0;
    }
    sort(v, v + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            seen[i] = true;
            int size = 1;
            ll a = v[i];
            while (a * k <= 1e9) {
                int nx = lower_bound(v, v + n, a * k) - v;
                if (nx != n && v[nx] == a * k) {
                    size++; seen[nx] = true;
                } else { 
                    break;
                }
                a *= k;
            }
            ans += ((size + 1) / 2);
        }
    }
    printf("%d\n", ans);
}


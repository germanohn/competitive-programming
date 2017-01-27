#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/* O(nlogn)
const int MAX = 500005;

int n;
ll v[MAX];
vector<int> pre, last;

int main () {
    scanf(" %d", &n);
    ll acc = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &v[i]);
        acc += v[i];
    }
    if (acc % 3 != 0) {
        printf("0\n");
        return 0;
    }
    ll cur = 0;
    for (int i = 0; i < n - 2; i++) {
        cur += v[i];
        if (cur == acc / 3) 
            pre.pb(i);
    }
    cur = 0;
    for (int i = n - 1; i > 1; i--) {
        cur += v[i];
        if (cur == acc / 3)
            last.pb(i);
    } 
    sort(last.begin(), last.end());
    ll ans = 0;
    for (int i = 0; i < pre.size(); i++) 
        ans += (last.size() - (lower_bound(last.begin(), last.end(), pre[i] + 2) - last.begin()));
    printf("%lld\n", ans);
}
*/

// O(n)
const int MAX = 500005;

int n;
int cont[MAX], v[MAX];
bool ok[MAX];

int main() {
    scanf(" %d", &n);
    ll acc = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &v[i]);
        acc += v[i];
    }
    if (acc % 3 != 0) {
        printf("0\n");
        return 0;
    }
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += v[i];
        if (cur == acc / 3)
            ok[i] = true;
    }
    cur = 0;
    for (int i = n - 1; i > 1; i--) {
        cur += v[i];
        cont[i] = cont[i + 1] + (cur == acc / 3);
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) 
        ans += (ok[i] * cont[i + 2]);
    printf("%lld\n", ans);
}

#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, m;
int c[N], w[N];
pii ans[N];
set<pii> avail;

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &c[i]);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &w[i]);
    
    ll all = 0;
    for (int i = 0; i < n; i++) {
        avail.insert(pii(w[i] * (100 - (c[i] % 100)), i));

        if ((c[i] % 100) == 0) {
            ans[i] = pii(c[i] / 100, 0);
            avail.erase(pii(w[i] * (100 - (c[i] % 100)), i));
        } else if (c[i] <= m) {
            m -= (c[i] % 100);
            ans[i] = pii(c[i] / 100, c[i] % 100);
        } else {
            int a, b;
            tie(a, b) = (*avail.begin());
            avail.erase(avail.begin());
            ans[i] = pii(c[i] / 100, c[i] % 100);
            ans[b] = pii(c[b] / 100 + 1, 0);
            all += a;
            m += (100 - (c[i] % 100));
        }
    }

    printf("%d\n", all);
    for (int i = 0; i < n; i++) 
        printf("%d %d\n", ans[i].ff, ans[i].ss);
}


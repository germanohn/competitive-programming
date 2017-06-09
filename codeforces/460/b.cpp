#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll a, b, c;
vector<int> ans;

ll fexp(ll b, ll e) {
    if (e == 0) return 1;
    if (e % 2 == 1) return b * fexp(b * b, e / 2);
    if (e % 2 == 0) return fexp(b * b, e / 2);
}

int main () {
    scanf(" %lld %lld %lld", &a, &b, &c);

    for (int i = 1; i <= 81; i++) {
        ll x = b * fexp(i, a) + c;

        if (x <= 0 || x >= 1e9)
            continue;

        int sum = 0;
        ll aux = x;
        while (aux > 0) {
            sum += (aux % 10);
            aux /= 10;
        }

        if (sum == i) 
            ans.pb(x);
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) 
        printf("%d ", ans[i]);
    if (ans.size() > 0) printf("\n");
}


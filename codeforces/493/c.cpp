#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 400005;

int n, m;
pii v[MAX];

int main() {
    scanf(" %d", &n);
    ll a = 0;
    for (int i = 0; i < n; i++) {
        v[i].ss = 1;
        scanf(" %d", &v[i].ff);
        a += 3;
    }
    scanf(" %d", &m);
    ll b = 0;
    for (int i = n; i < n + m; i++) {
        v[i].ss = 2;
        scanf(" %d", &v[i].ff);
        b += 3; 
    }
    sort(v, v + n + m);
    pii ans = pii(a, b);
    for (int i = 0; i < n + m; i++) {
        if (v[i].ss == 1) 
            a--;
        else {
            b--;
            if (a - b > ans.ff - ans.ss)
                ans = pii(a, b);
        }
    }
    printf("%d:%d\n", ans.ff, ans.ss);
}

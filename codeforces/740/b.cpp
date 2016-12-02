#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n, m;
int v[MAX], acc[MAX];
pii sub[MAX];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }

    acc[0] = 0;
    for (int i = 1; i <= n; i++) {
        acc[i] = v[i - 1] + acc[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int l, r, tmp = 0;
        scanf(" %d %d", &l, &r);
        tmp = acc[r] - acc[l - 1];
        if (tmp > 0)
            ans += tmp;
    }

    printf("%d\n", ans);
}


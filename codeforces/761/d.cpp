#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, l, r;
int a[N], b[N];
pii p[N];

int main () {
    scanf(" %d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &p[i].ff);
        p[i].ss = i;
    }
    sort(p, p + n);

    int pos, prev_ci;
    pos = p[0].ss;
    b[pos] = l;
    prev_ci = b[pos] - a[pos];
    bool ok = true;
    for (int i = 1; ok && i < n; i++) {
        pos = p[i].ss;
        b[pos] = max(l, prev_ci + a[pos] + 1);
        if (b[pos] > r) 
            ok = false;
        prev_ci = b[pos] - a[pos];
    }

    if (ok) {
        for (int i = 0; i < n; i++) 
            printf("%d ", b[i]);
        printf("\n");
    } else 
        printf("-1\n");
}


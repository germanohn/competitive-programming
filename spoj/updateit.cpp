#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int t, n, u, l, r, val, q;
int bit[MAX];

void update (int idx, int val) {
    for (int i = idx; i <= n; i += i & -i) 
        bit[i] += val;
}

int query (int ind) {
    
    int sum = 0;
    for (int i = ind; i > 0; i -= i & -i) {
        sum += bit[i];
    }
    return sum;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        for (int i = 0; i <= n; i++)
            bit[i] = 0;
        scanf ("%d %d", &n, &u);
        for (int i = 0; i < u; i++) {
            scanf ("%d %d %d", &l, &r, &val);
            update (l + 1, val);
            update (r + 2, -val);
        }
        scanf ("%d", &q);
        int idx;
        for (int i = 0; i < q; i++) {
            scanf ("%d", &idx);
            printf ("%d\n", query (idx+1) );
        }
    }
}


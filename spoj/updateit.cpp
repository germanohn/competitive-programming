#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int bit[MAX];
int t, n, u, l, r, val, q, idx;

void update (int idx, int val) {
    for (int i = idx; i <= n; i += i & -i) 
        bit[i] += val;
}

int query (int idx) {
    int sum = 0; 
    for (int i = idx; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &u);
        for (int i = 0; i <= n; i++)
            bit[i] = 0;
        for (int j = 1; j <= u; j++) {
            scanf ("%d %d %d", &l, &r, &val);
            update (l + 1, val);
            update (r + 1, -val);
        }
        scanf ("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf ("%d", &idx);
            printf ("idx %d\n", idx);
            printf ("%d\n", query (idx + 1) - query(idx));
        }   
    }

}

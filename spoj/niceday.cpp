#include <bits/stdc++.h>

using namespace std;

typedef struct tipo {
    int a, b, c;
} rank;

rank p[100005];
int t, n, ans, bit[100005];
map<int, int> m;

bool compA (rank x, rank y) {
    return x.a < y.a;
}

void update (int idx, int val) {
    for (int i = idx; i <= n; i += i & -i)
        bit[i] = min (bit[i], val);
}

int query (int idx) {
    int res = 123456; 
    for (int i = idx; i > 0; i -= i & -i)
        res = min (res, bit[i]);
    return res;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        ans = n;
        for (int j = 0; j <= n; j++) 
            bit[j] = 123456;

        for (int j = 0; j < n; j++) 
            scanf ("%d %d %d", &p[j].a, &p[j].b, &p[j].c);       

        sort (p, p + n, compA);
        
        for (int j = 0; j < n; j++) {
            if (p[j].c > query (p[j].b - 1)) ans--;
            update (p[j].b, p[j].c);
        }
        printf ("%d\n", ans);
    }
}

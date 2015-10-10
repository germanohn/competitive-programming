#include <bits/stdc++.h>

using namespace std;

typedef struct tipo {
    int b, i, r;    
} ball;

ball l[500005];
int n, ans, bit[500005];
map<int, int> m;

bool compI (ball a, ball b) {
    return a.i > b.i;
}

bool compB (ball x, ball y) {
    if (x.b != y.b) return x.b > y.b;
    return x.i > y.i;
}

void update (int idx, int val) {
    for (int i = idx; i <= n; i += i & -i)
        bit[i] = max (bit[i], val);
}

int query (int idx) {
    int res = 0;
    for (int i = idx; i > 0; i -= i & -i) {
        res = max (res, bit[i]);
    }
    return res;
}

int main () {
    scanf ("%d", &n);
    for (int j = 0; j < n; j++) 
        scanf ("%d", &l[j].b);
    for (int j = 0; j < n; j++)
        scanf ("%d", &l[j].i);
    for (int j = 0; j < n; j++) 
        scanf ("%d", &l[j].r);

    sort (l, l + n, compI);
    int k = 1;
    for (int j = 0; j < n; j++) {
        if (m.find (l[j].i) == m.end ()) m[l[j].i] = k++;
        l[j].i = m[l[j].i];
    }

    sort (l, l + n, compB);
    for (int j = 0; j < n; j++) {
        if (l[j].r < query (l[j].i - 1)) ans++;
        update (l[j].i, l[j].r);
    }
    printf ("%d\n", ans);
}

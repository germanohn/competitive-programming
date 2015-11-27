#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;

int n, m;
int a, b, va[MAX], vb[MAX];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &va[i]);
    }
    sort (va, va+n);
    int x;
    for (int i = 0; i < m; i++) {
        scanf ("%d", &vb[i]);
        x = upper_bound (va, va+n, vb[i]) - va;
        printf ("%d%c", x, i == m-1 ? '\n' : ' ');
    }
}

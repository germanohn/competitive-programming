#include <bits/stdc++.h>
#define MAX 400100
using namespace std;

int n, a, b;
char c;

struct animal {
    int H, E, R;
};

animal seg[MAX], lazy[MAX];

void decide () {
    if (seg.H > 0) seg.E = seg.H, seg.H = 0;
    else if (seg.E > 0) seg.R = seg.E, seg.E = 0;
    else if (seg.R > 0) seg.H = seg.R, seg.R = 0;    
}

void propagate (int l, int r, int n) {
    decide ();
    if (a != b) {
        lazy
    }
}

void update (int l, int r, int n, int a, int b) {
    propagate (int l, int r, int n);
    if (b < l || a > r) return;
    if (a >= l && b <= r) {
        decide ();
        if (l != r) {
                
        }
        return;
    }
    int m = (l+r)/2;
    update (l, m, n, a, b);
    update (m+1, r, n, a, b);
    
}

void update (int a, int b) {
    update (0, n-1, 1, a, b);
}

int main () {
    int m;
    while (scanf ("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < m; i++) {
            scanf (" %c %d %d", &c, &a, &b);
            if (c == 'C') {
                update (a, b);    
            }            
        }
    }
}

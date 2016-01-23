#include <bits/stdc++.h>
using namespace std;

int seg[400100];
int n;

void update (int l, int r, int no, int val, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[no] = val;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*no, val, ind);
    update (m+1, r, 2*no+1, val, ind);
    seg[no] = seg[2*no]*seg[2*no+1];
}

void update (int val, int ind) {
    update (0, n-1, 1, val, ind);
}

int query (int l, int r, int no, int a, int b) {
    if (l > b || r < a) {
        return 1;
    }
    if (l >= a && r <= b) {
        return seg[no];
    }
    int m = (l+r)/2;
    return query (l, m, 2*no, a, b) * query (m+1, r, 2*no+1, a, b);
}

int query (int a, int b) {
    return query (0, n-1, 1, a, b);
}

int main () {
    int k, num;
    memset (seg, 1, sizeof seg);
    while (scanf ("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf ("%d", &num);
            if (num > 0) num = 1;
            else if (num < 0) num = -1;
            else num = 0;
            update (num, i);
        }
        char letra;
        int a, b, ind, val;
        for (int i = 0; i < k; i++) {
            scanf (" %c", &letra);
            if (letra == 'C') {
                scanf ("%d %d", &ind, &val);
                if (val > 0) val = 1; 
                else if (val < 0) val = -1;
                else val = 0;
                update (val, ind-1);
            }
            else if (letra == 'P') {
                scanf ("%d %d", &a, &b);
                int sinal = query (a-1, b-1);
                if (sinal == 0) printf ("0");
                else if (sinal > 0) printf ("+");
                else printf ("-");
            }
        }
        printf ("\n");
    }
    
}

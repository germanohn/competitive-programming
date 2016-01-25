#include <bits/stdc++.h>
#define debug(args...) //fprintf (stderr, args)
#define MAX 4000100
using namespace std;

int n;
char c;

struct animal {
    int H, E, R;
};

animal seg[MAX];
int lazy[MAX];

struct animal operator + (const animal &a, const animal &b) {
    animal c;
    c.H = a.H + b.H, c.E = a.E + b.E, c.R = a.R + b.R;
    return c;
}

void propagate (int l, int r, int no) {
    animal s;
    for (int i = 0; i < lazy[no] % 3; i++) {
        s.H = seg[no].R, s.E = seg[no].H, s.R = seg[no].E;
        seg[no] = s; 
    }
    if (l != r) {
        lazy[2*no] += lazy[no];
        lazy[2*no+1] += lazy[no];        
    }
    lazy[no] = 0;
}

void update (int l, int r, int no, int a, int b) {
    propagate (l, r, no);
    if (b < l || a > r) return;
    if (l >= a && r <= b) {
        animal s;
        s.H = seg[no].R, s.E = seg[no].H, s.R = seg[no].E;
        seg[no] = s;
        debug ("UPDATE %d %d %d\n", s.H, s.E, s.R);
        debug ("%d %d %d\n", seg[no].H, seg[no].E, seg[no].R);
        if (l != r) {
            lazy[2*no]++;            
            lazy[2*no+1]++;
        }
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*no, a, b);
    update (m+1, r, 2*no+1, a, b);
    seg[no] = seg[2*no] + seg[2*no+1];
}

void update (int a, int b) {
    update (0, n-1, 1, a, b);
}

animal query (int l, int r, int no, int a, int b) {
    debug ("QUERY %d %d\n", l, r);
    propagate (l, r, no);
    if (l >= a && r <= b) return seg[no];
    if (a > r || b < l) {
        animal aux;
        aux.H = 0, aux.E = 0, aux.R = 0;
        return aux;
    }
    int m = (l+r)/2;
    return query (l, m, 2*no, a, b) + query (m+1, r, 2*no+1, a, b);
}

animal query (int a, int b) {
    return query (0, n-1, 1, a, b);
}

void build (int l, int r, int no, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[no].R = 0, seg[no].H = 1, seg[no].E = 0;
        return;
    }
    int m = (l+r)/2;
    build (l, m, 2*no, ind);
    build (m+1, r, 2*no+1, ind);
    seg[no] = seg[2*no] + seg[2*no+1];
}

int main () {
    int m, a, b;
    while (scanf ("%d %d", &n, &m) != EOF) {
        memset (lazy, 0, sizeof lazy);
        for (int i = 0; i < n; i++) 
            build (0, n-1, 1, i);
        for (int i = 0; i < m; i++) {
            scanf (" %c %d %d", &c, &a, &b);
            if (c == 'M') {
                update (a-1, b-1);    
            }           
            else {
                animal aux = query (a-1, b-1);
                printf ("%d %d %d\n", aux.H, aux.E, aux.R); 
            } 
        }
        printf ("\n");
    }
}

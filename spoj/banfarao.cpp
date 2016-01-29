#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAX 400005
#define MIN -1000000000
using namespace std;
typedef pair<int, int> pii;

struct celula {
    int esq, dir, sum, best;
    int qesq, qdir, qsum, qbest; 
};

celula seg[MAX];

void join (int n) {
    pii a = pii (seg[2*n].esq, seg[2*n].qesq), b = pii (seg[2*n].sum + seg[2*n+1].esq, seg[2*n].qsum + seg[2*n+1].qesq);
    pii rta, c = pii (seg[2*n].sum + seg[2*n+1].sum, seg[2*n].qsum + seg[2*n+1].qsum);
    rta = max (a, max (b, c));
    seg[n].esq = rta.ff, seg[n].qesq = rta.ss; 

    a = pii (seg[2*n+1].dir, seg[2*n+1].qdir), b = pii (seg[2*n+1].sum + seg[2*n].dir, seg[2*n+1].qsum + seg[2*n+1].qdir);
    c = pii (seg[2*n+1].sum + seg[2*n].sum, seg[2*n+1].qsum + seg[2*n].qsum);
    rta = max (a, max (b, c));
    seg[n].dir = rta.ff, seg[n].qdir = rta.ss;

    /*a = pii (seg[2*n].mid, seg[2*n].qmid), b = pii (seg[2*n+1].mid, seg[2*n+1].qmid);
    c = pii (seg[2*n].sum + seg[2*n+1].sum, seg[2*n].qsum + seg[2*n+1].qsum);
    rta = max (a, max (b, c));
    seg[n].mid = rta.ff, seg[n].qmid = rta.ss;*/
    
    seg[n].sum = seg[2*n].sum + seg[2*n+1].sum, seg[n].qsum = seg[2*n].qsum + seg[2*n+1].qsum;
    pii k = pii (seg[n].esq, seg[n].qesq), p = pii (seg[n].dir, seg[n].qdir);
    pii m = pii (seg[n].sum, seg[n].qsum); 
    rta = max (k, max (p, m));
    seg[n].best = rta.ff, seg[n].qbest = rta.ss;
}

celula junta (celula x, celula y, celula &ans) {
    
    pii a = pii (x.esq, x.qesq), b = pii (x.sum + y.esq, x.qsum + y.qesq);
    pii rta, c = pii (x.sum + y.sum, x.qsum + y.qsum);
    rta = max (a, max (b, c));
    ans.esq = rta.ff, ans.qesq = rta.ss;

    a = pii (y.dir, y.qdir), b = pii (y.sum + x.dir, y.qsum + x.qdir);
    c = pii (y.sum + x.sum, y.qsum + x.qsum);
    rta = max (a, max (b, c)); 
    ans.dir = rta.ff, ans.qdir = rta.ss;

    /*a = pii (x.mid, x.qmid), b = pii (y.mid, y.qmid), c = pii (x.sum + y.sum, x.qsum + y.qsum);
    rta = max (a, max (b, c));
    ans.mid = rta.ff, ans.qmid = rta.ss;*/

    ans.sum = x.sum + y.sum, ans.qsum = x.qsum + y.qsum;
    pii k = pii (ans.sum, ans.qsum), p = pii (ans.dir, ans.qdir);
    pii m = pii (ans.esq, ans.qesq);
    rta = max (k, max (p, m));
    ans.best = rta.ff, ans.qbest = rta.ss;
}

void update (int l, int r, int n, int v, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[n].esq = seg[n].dir = seg[n].sum = seg[n].best = v;
        seg[n].qesq = seg[n].qdir = seg[n].qsum = seg[n].qbest = 1;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*n, v, ind);
    update (m+1, r, 2*n+1, v, ind);
    join (n);
}

celula query (int l, int r, int n, int a, int b) {
    celula ans;
    if (a > r || b < l) {
       ans.dir = ans.esq = ans.sum = ans.best = MIN;
       ans.qdir = ans.qesq = ans.qsum = ans.qbest = 0;
       return ans;
    }
    if (l >= a && r <= b) {
        return seg[n];
    }
    int m = (l+r)/2;
    celula x, y;
    x = query (l, m, 2*n, a, b), y = query (m+1, r, 2*n+1, a, b);        
    junta (x, y, ans);
    return ans;
}

int main () {
    int t, conta, aux, q, a, b;
    celula ans; 
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &conta);
        for (int i = 0; i < 4*conta; i++)
            seg[i].esq = seg[i].dir = seg[i].best = seg[i].sum = MIN;
        for (int i = 0; i < conta; i++) {
            scanf ("%d", &aux);
            update (0, conta-1, 1, aux, i);
        }
        printf ("\n");
        int cont = 1;
        for (int i = 1; i < 3*conta; i++)
            printf ("no %d  esq %d %d best %d %d dir %d %d sum %d %d\n", cont++, 
                    seg[i].esq, seg[i].qesq, seg[i].best, seg[i].qbest, seg[i].dir, 
                    seg[i].qdir, seg[i].sum, seg[i].qsum);
        scanf ("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &a, &b);
            ans = query (0, conta-1, 1, a-1, b-1);
            /*pii k, l, m, p, rta;
            k = pii (ans.esq, ans.qesq), l = pii (ans.dir, ans.qdir); 
            m = pii (ans.mid, ans.qmid), p = pii (ans.sum, ans.qsum);
            rta = max (k, max (l, max (m, p)));*/
            printf ("%d %d\n", ans.best, ans.qbest);    
        }
    }
}

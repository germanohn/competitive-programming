#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAX 400005
#define MIN -100000005
using namespace std;
typedef pair<int, int> pii;

struct celula {
    int esq, dir, sum, mid, best;
    int qesq, qdir, qsum, qmid, qbest; 
};

celula seg[MAX];

void join (int n) {

    pii a = pii (seg[2*n].esq, seg[2*n].qesq), b = pii (seg[2*n].sum + seg[2*n+1].esq, seg[2*n].qsum + seg[2*n+1].qesq);
    pii rta = max (a, b), c, d;
    seg[n].esq = rta.ff, seg[n].qesq = rta.ss; 

    a = pii (seg[2*n+1].dir, seg[2*n+1].qdir), b = pii (seg[2*n+1].sum + seg[2*n].dir, seg[2*n+1].qsum + seg[2*n].qdir);
    rta = max (a, b);
    seg[n].dir = rta.ff, seg[n].qdir = rta.ss;

    a = pii (seg[2*n].mid, seg[2*n].qmid), b = pii (seg[2*n+1].mid, seg[2*n+1].qmid);
    c = pii (seg[2*n].dir + seg[2*n+1].esq, seg[2*n].qdir + seg[2*n+1].qesq);
    rta = max (a, max (b, c));
    seg[n].mid = rta.ff, seg[n].qmid = rta.ss;
    
    seg[n].sum = seg[2*n].sum + seg[2*n+1].sum, seg[n].qsum = seg[2*n].qsum + seg[2*n+1].qsum;
    a = pii (seg[n].esq, seg[n].qesq), b = pii (seg[n].dir, seg[n].qdir);
    c = pii (seg[n].sum, seg[n].qsum), d = pii (seg[n].mid, seg[n].qmid); 
    pii e = pii (seg[2*n].dir, seg[2*n].qdir), f = pii (seg[2*n+1].esq, seg[2*n+1].qesq);
    rta = max (e, f);
    rta = max (rta, max (a, max (b, max (c, d))));
    seg[n].best = rta.ff, seg[n].qbest = rta.ss;
}

celula junta (celula x, celula y, celula &ans, int l, int r) {
    /*printf ("JUNTA l %d r %d\n", l, r);
        printf ("x.esq %d x.best %d x.dir %d x.sum %d y.esq %d y.best %d y.dir %d y.sum %d",
            x.esq, x.best, x.dir, x.sum, y.esq, y.best, y.dir, y.sum);
    printf (" x.mid %d y.mid %d\n", x.mid, y.mid);
    */pii a = pii (x.esq, x.qesq), b = pii (x.sum + y.esq, x.qsum + y.qesq);
    pii rta = max (a, b), c, d;
    ans.esq = rta.ff, ans.qesq = rta.ss;
    //printf ("\nans.esq %d %d\n", ans.esq, ans.qesq);
    

    a = pii (y.dir, y.qdir), b = pii (y.sum + x.dir, y.qsum + x.qdir);
    rta = max (a, b); 
    ans.dir = rta.ff, ans.qdir = rta.ss;
    //printf ("ans.dir %d %d\n", ans.dir, ans.qdir);

    a = pii (x.mid, x.qmid), b = pii (y.mid, y.qmid);
    c = pii (x.dir + y.esq, x.qdir + y.qesq);
    rta = max (a, max (b, c));
    ans.mid = rta.ff, ans.qmid = rta.ss;
    //printf ("ans.mid %d %d\n", ans.mid, ans.qmid);

    ans.sum = x.sum + y.sum, ans.qsum = x.qsum + y.qsum;
    a = pii (ans.sum, ans.qsum), b = pii (ans.dir, ans.qdir);
    c = pii (ans.esq, ans.qesq), d = pii (ans.mid, ans.qmid);
    pii e = pii (x.dir, x.qdir), f = pii (y.esq, y.qesq);
    rta = max (e, f);
    rta = max (rta, max (a, max (b, max (c, d))));
    ans.best = rta.ff, ans.qbest = rta.ss;
            
    //printf ("ans.best %d %d\n\n", ans.best, ans.qbest);
}

void update (int l, int r, int n, int v, int ind) {
    if (ind < l || ind > r) return;
    if (l == r) {
        seg[n].esq = seg[n].dir = seg[n].sum = seg[n].mid = seg[n].best = v;
        seg[n].qesq = seg[n].qdir = seg[n].qsum = seg[n].qmid = seg[n].qbest = 1;
        return;
    }
    int m = (l+r)/2;
    update (l, m, 2*n, v, ind);
    update (m+1, r, 2*n+1, v, ind);
    join (n);
}

celula query (int l, int r, int n, int a, int b) {
    //printf ("l %d r %d a %d b %d\n", l, r, a, b);
    if (a > r || b < l) {
      //  printf ("FORA\n");
    celula ans;
       ans.dir = ans.esq = ans.sum = ans.mid = ans.best = MIN;
       ans.qdir = ans.qesq = ans.qsum = ans.qmid = ans.qbest = 0;
       return ans;
    }
    if (l >= a && r <= b) {
        /*    printf ("QUERY no %d  esq %d %d best %d %d dir %d %d sum %d %d\n", n, 
                    seg[n].esq, seg[n].qesq, seg[n].best, seg[n].qbest, seg[n].dir, 
                    seg[n].qdir, seg[n].sum, seg[n].qsum);
        */return seg[n];
    }
    int m = (l+r)/2;
    celula x, y, ans;
    x = query (l, m, 2*n, a, b), y = query (m+1, r, 2*n+1, a, b);        
    junta (x, y, ans, l, r);
    //printf ("ANTES DA RTA\n");
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
        //printf ("\n");
        int cont = 1;
        /*for (int i = 1; i < 3*conta; i++)
            printf ("no %d  esq %d %d best %d %d dir %d %d sum %d %d\n", cont++, 
                    seg[i].esq, seg[i].qesq, seg[i].best, seg[i].qbest, seg[i].dir, 
                    seg[i].qdir, seg[i].sum, seg[i].qsum);
        */scanf ("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf ("%d %d", &a, &b);
            ans = query (0, conta-1, 1, a-1, b-1);
            /*printf ("ans  esq %d %d best %d %d dir %d %d sum %d %d\n",  
                    ans.esq, ans.qesq, ans.best, ans.qbest, ans.dir, 
                    ans.qdir, ans.sum, ans.qsum);
              */  printf ("%d %d\n", ans.best, ans.qbest);    
        }
    }
}

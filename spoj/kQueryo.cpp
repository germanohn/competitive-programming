#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 30005;

int n;
int vp[MAX];
vi t[4*MAX];

vi merge (vi &l, vi &r) {
    vi v;
    int lenL = l.size (), lenR = r.size ();
    int i = 0, j = 0;
    while (i < lenL && j < lenR) {
        if (l[i] < r[j]) 
            v.pb (l[i]), i++;
        else 
            v.pb (r[j]), j++;
    }
    while (i < lenL)
        v.pb (l[i]), i++;
    while (j < lenR)
        v.pb (r[j]), j++;
    return v;
}

void update (int no, int l, int r) {
    if (l == r) {
        t[no].pb (vp[l]);
        return;
    }
    int mid = (l+r)/2;
    update (2*no, l, mid);
    update (2*no + 1, mid+1, r);
    t[no] = merge (t[2*no], t[2*no +1]); 
    return;
} 

int query (int no, int l, int r, int a, int b, int k) {
    if (a > r || b < l) 
        return 0;
    if (l >= a && r <= b) 
        return t[no].end () - upper_bound (t[no].begin (), t[no].end (), k);
    int mid = (l+r)/2;
    int r1 = query (2*no, l, mid, a, b, k);
    int r2 = query (2*no+1, mid+1, r, a, b, k); 
    return r1+r2;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        for (int i = 0; i <= 4*n; i++)
            t[i].clear ();
        for (int i = 0; i < n; i++) {
            scanf ("%d", &vp[i]);
        }
        update (1, 0, n-1);
        int q, ans = 0;
        scanf ("%d", &q);
        while (q--) {
            int a, b, c;
            scanf ("%d %d %d", &a, &b, &c);
            a ^= ans, b ^= ans, c ^= ans;
            if (a < 1) a = 1;
            if (b > n) b = n;
            if (a > b) 
                ans = 0;
            else 
                ans = query (1, 0, n-1, a-1, b-1, c);
            printf ("%d\n", ans);
        }
    }
    return 0;
}





#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 500005;
const int MAXN = 1000000000;

int n, m, d, l;
int hole[MAX], music[MAX];
set<int> cd;

int calc (int pos) {
    int esq, dir, tam, posE, posD, val;
    set<int>::iterator a, b, atual;

    posE = max (pos-l, 0);
    posD = min (pos+l, MAXN);
    a = b = cd.find (pos);
    a--, b++;

    // esq
    val = *a;
    val = min (MAXN, val+l);
    if (val < posE)
        esq = posE;
    else
        esq = val+1; 
    // dir 
    val = *b;
    val = max (0, val-l);
    if (val <= posD)
        dir = val-1;
    else 
        dir = posD;
    
    if (esq > dir) 
        return 0;

    int qtd = upper_bound (hole, hole+n, dir) - lower_bound (hole, hole+n, esq);
    return qtd;
}

int main () {
    scanf ("%d %d %d %d", &n, &m, &d, &l);
    hole[0] = 0;
    for (int i = 1; i < n; i++) 
        scanf ("%d", &hole[i]);
    int pos, ans = 0, a;
    cd.insert (-2e9);
    cd.insert (2e9);
    for (int i = 0; i < m; i++) {
        scanf ("%d", &a);
        cd.insert (a);
        ans += calc (a);
    }
    printf ("%d\n", ans);
    int p, r;
    while (d--) {
        scanf ("%d %d", &p, &r);
        ans -= calc (p);
        cd.erase (p);
        cd.insert (r);
        ans += calc (r);
        printf ("%d\n", ans);

    }
}


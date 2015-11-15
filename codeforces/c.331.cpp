#include <bits/stdc++.h>
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, w[MAX];
pii v[MAX];
map<int, int> mw, mv;
set<int> s;
map<int, vector<pii> > mvp;
map<int, vector<int> > wil;

bool comp (pii a, pii b) {
    return a.ff <= b.ff && a.ss <= b.ss;
}

int main () {
    scanf ("%d", &n);
    int dif;
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &v[i].ff, &v[i].ss); 
        dif = v[i].ss - v[i].ff;
        if (mv.find (dif) == mv.end ()) mv[dif] = 1;
        else mv[dif]++;
        mvp[dif].pb (mp (v[i].ff, v[i].ss));
    }
    for (int i = 0; i < n; i++) {
        scanf ("%d", &w[i]);
        s.insert (w[i]);
        if (mw.find (w[i]) == mw.end ()) mw[w[i]] = 1;
        else mw[w[i]]++;
        wil[w[i]].pb (i);
    }
    set<int>::iterator i;
    for (i = s.begin (); i != s.end (); i++) {
        if (mw[*i] != mv[*i]) {
            printf ("NO\n");
            return 0;
        }
    }
    pii vp[MAX];
    for (i = s.begin (); i != s.end (); i++) {
        for (int j = 0; j < mvp[*i].size (); j++)
            vp[j] = mvp[*i][j];
        int tam = mvp[*i].size ();
        sort (vp, vp + tam, comp);
        for (int j = 0; j < wil[*i].size (); j++) {
            int pos = wil[*i][j];
            v[pos] = vp[j];
        }
    }
    int maff = v[0].ff, mass = v[0].ss;
    for (int i = 1; i < n; i++) {
        if ((v[i].ff < maff && v[i].ss <= mass) || (v[i].ff <= maff && v[i].ss < mass)) {
            printf ("NO\n");
            return 0;
        }
        if (v[i].ff >= maff && v[i].ss >= mass) {
            maff = v[i].ff;
            mass = v[i].ss;
        }
    }
    printf ("YES\n");
    for (int i = 0; i < n; i++) {
        printf ("%d %d\n", v[i].ff, v[i].ss);
    }
}

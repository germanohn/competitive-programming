#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 100005;

int n;
int v[MAX], destroy[MAX];
ll acc[MAX];
map<pii, ll> inter;
set<int> gone;
multiset<ll> sum;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }

    acc[0] = 0;
    for (int i = 0; i < n; i++) 
        acc[i+1] = acc[i] + v[i];

    for (int i = 0; i < n; i++) 
        scanf ("%d", &destroy[i]);

    inter[pii (1, n)] = acc[n];
    sum.insert (acc[n]);
    printf ("maior %lld\n", *sum.rbegin ());

    for (int i = 0; i < n; i++) {
        printf ("\ni %d\n", i);
        int a, ans, l, r;
        pii dead;

        a = destroy[i];
        gone.insert (a);
        // l, r sao os nao destruidos mais longe de a, antes dos primeiros destruidos
        l = *gone.find (gone.find (a) - 1);
        r = *gone.find (gone.find (a) + 1);
        dead = pii (l+1, r-1);

        printf ("antes i %d maior %lld\n", i, *sum.rbegin ());
        sum.erase (inter[dead]);
        if (!sum.empty ()) printf ("depois i %d maior %lld\n\n", i, *sum.rbegin ());
        else printf ("depois i %d maior %lld\n", i, 0);

        inter[dead] = 0;

        int ant, dep;
        ant = *gone.find (gone.find (l) - 1);
        dep = *gone.find (gone.find (l) + 1);
        if (dep - ant >= 0) {
            printf ("l\n");
            pii nw = pii (ant, dep);
            int val = acc[dep] - acc[ant-1];
            printf ("ff %d ss %d val %lld\n", nw.ff, nw.ss, val);

            inter[nw] = val;
            sum.insert (val);
        }
        ant = *gone.find (gone.find (r) - 1);
        dep = *gone.find (gone.find (r) + 1);
        if (dep - ant >= 0) {
            printf ("l\n");
            pii nw = pii (ant, dep);
            int val = acc[dep] - acc[ant-1];
            printf ("ff %d ss %d val %lld\n", nw.ff, nw.ss, val);

            inter[nw] = val;
            sum.insert (val);
        }

        if (!sum.empty ()) {
            printf ("i %d size %d\n", i, sum.size ());
            ans = *sum.rbegin ();
        }
        else ans = 0;
        printf ("%lld\n", ans);
    }
}


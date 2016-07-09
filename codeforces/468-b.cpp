#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 1e5 + 5;

int n, a, b;
int seen[MAX];
pii v[MAX];

bool compare (pii x, pii y) {
    return x.ss < y.ss;
}

int main () {
    scanf ("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].ff);
        v[i].ss = i;
    }
    sort (v, v+n);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int lo, hi;
        if (!seen[v[i].ff]) {
            // primeiro tenta colocar em a
            int x = a-v[i].ff;
            //printf ("a-v[i].ff %d\n", x);
            lo = 0, hi = n-1;
            while (lo != hi) {
                int mid = (lo+hi+1) / 2;
                if (v[mid].ff == x) 
                    lo = mid;
                else if (v[mid].ff < x)
                    lo = mid+1;
                else 
                    hi = mid-1;
            }
            //printf ("v[lo].ff %d\n\n", v[lo].ff);
            if (v[lo].ff == x && seen[x] != 2)
               seen[x] = 1, seen[v[i].ff] = 1;
            else { 
                // segundo tenta colocar em b    
                int x = b-v[i].ff;
             //   printf ("b-v[i].ff %d\n", x);
                lo = 0, hi = n-1;
                while (lo != hi) {
                    int mid = (lo+hi+1) / 2;
                    if (v[mid].ff == x) 
                        lo = mid;
                    else if (v[mid].ff < x)
                        lo = mid+1;
                    else 
                        hi = mid-1;
                }
                if (v[lo].ff == x && seen[x] != 1)
                    seen[x] = 2, seen[v[i].ff] = 2;
            }
            if (seen[v[i].ff] != 1 && seen[v[i].ff] != 2)
                ok = false;
        }
    }
    if (ok) {
        sort (v, v+n, compare);
        printf ("YES\n");
        for (int i = 0; i < n; i++) {
            if (seen[v[i].ff] == 1)
                printf ("0 ");
            else
                printf ("1 ");
        }    
        printf ("\n");
    } else {
        printf ("NO\n");
    }
}


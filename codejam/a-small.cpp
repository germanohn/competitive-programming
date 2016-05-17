#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, t;
pii v[30];

bool cmp (pii a, pii b) {
    return a.ff > b.ff;
}

int main () {
    scanf ("%d", &t);
        int cont = 1;
    while (t--) {
        scanf ("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i].ff);
            v[i].ss = i;
            sum += v[i].ff;
        }
        // sempre tenho que ver se o segundo maior nao fica com 
        printf ("Case #%d: ", cont++);
        while (sum > 0) {
            sort (v, v+n, cmp);
            //for (int i = 0; i < n; i++) {
             //   printf ("%d ", v[i].ff);
            //}
            //printf ("\n");
            //printf ("v[i] %d sum/2 %d\n", v[1].ff, (sum+1)/2);
            // tirar um do primeiro
            if (v[1].ff < (sum+1)/2) {
                //printf ("entrei\n");
                v[0].ff--;
                sum--;
                printf ("%c ", v[0].ss+'A');
            }
            // tirar dois do primeiro
            else if (v[1].ff <= (sum-1)/2) {
                v[0].ff -= 2;
                sum -= 2;
                printf ("%c%c ", v[0].ss+'A', v[0].ss+'A');
            }
            // tirar um do primeiro e um do segundo
            else if (n == 2 || v[2].ff <= (sum-1)/2) {
                v[0].ff--, v[1].ff--;
                sum -= 2;
                printf ("%c%c ", v[0].ss+'A', v[1].ss+'A');
            }
        }
        printf ("\n");
    }
}


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
int v[MAX];
set<int> dif;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        dif.insert (v[i]);
    }
    sort (v, v+n);
    if (dif.size () > 3) {
        printf ("NO\n");
        return 0;
    } else {
        if (dif.size () == 1 || dif.size () == 2) {
            printf ("YES\n");
        } else {
            int ant = v[0];
            int x = -1;
            bool ok = true;
            for (int i = 1; ok && i < n; i++) {
                if (v[i] != ant) {
                    if (x == -1) x = v[i]-ant;
                    else {
                        if (v[i]-ant != x) ok = false; 
                    }
                    ant = v[i];
                }
            }
            if (ok) {
                printf ("YES\n");
            } else {
                printf ("NO\n");
            }
        }
    }
}

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

const int MAX = 100005;

int t, n;
int v[MAX], p[MAX];

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
        }
        bool f = false;
        int ant = v[0], posAnt = 0;
        for (int i = 1; i < n; i++) {
            if (v[i] != ant) {
                if (i - posAnt >= 3) 
                    f = true;
                ant = v[i];
                posAnt = i;
            }
        }
        if (n - posAnt >= 3)
            f = true;
        if (f) 
            printf ("Yes\n");
        else 
            printf ("No\n");
    }
}


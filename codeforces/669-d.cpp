#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int n, q, troca, x, t, l, r;
int v[MAX];
void chan () {
    
    int cont = n/2;
    for (int i = l; cont > 0; i = (i+2) % n) {
        if (i == 0)
            i = n;
        if (i == n) {
            int aux = v[i];
            v[i] = v[1];
            v[1] = aux;
        } else {
            int aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
            cont -= 2;
    }
}

int main () {
    scanf ("%d %d", &n, &q);
    l = 1, r = n;
    for (int i = 1; i <= n; i++) 
        v[i] = i;
    bool f = false;
    for (int i = 0; i < q; i++) {
        scanf ("%d", &t);
        if (t == 1) {
            if (troca != 1) {
                chan ();
                troca = 0;
            }
            scanf ("%d", &x);
            if (x > 0) {
                l = (l + (n - x%n)) % n;
            } else {
                x = abs (x);
                l = (l + (x%n)) % n;
            }
            if (l == 0)
                l = n;
            if (l == 1)
                r = n;
            else 
                r = l-1;
        } else {
            troca = (troca+1) % 2;
        }
    }
    if (troca == 1) {
        chan ();
    }
    int cont = n;
    for (int i = l; cont > 0; i++) {
        if (i == 0)
            i = n;

        printf ("%d ", v[i]);
        cont--;
   }
    printf ("\n");
}


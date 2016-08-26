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

const int MAX = 105;

int n, s, t;
int ans[MAX];

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd (b, a%b);
}

void solve (int i, int falta) {
    if (i == t) {
        if (falta == 0) {
            for (int i = 0; i < t-1; i++) printf ("%d ", ans[i]);
            printf ("%d\n", ans[t-1]);
        } else {
            return;
        }
    }
    int nx;
    if (i == 0) nx = 1;
    else nx = ans[i-1];
    for (; nx <= falta; nx++) {
        if (i != t-1 && ((falta-nx)/(t-i-1)) < nx) break;
        bool ok = true;
        for (int j = 0; ok && j < i; j++)
            if (ans[j] != 1 && gcd (ans[j], nx) != 1) ok = false;
        if (ok) {
            ans[i] = nx; 
            solve (i+1, falta-nx); 
            ans[i] = 0;
        }
    }
    return;
}

int main () {
    scanf ("%d", &n);
    int caso = 1;
    while (n--) {
        scanf ("%d %d", &s, &t);
        printf ("Case %d:\n", caso++);
        solve (0, s);
    }
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

int n;
int v[105];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    int l, r;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            l = i;
        } else if (v[i] == n) {
            r = i;
        }
    }
    if (l > r) swap (l, r);
    int ans = max (r, n-l-1);
    printf ("%d\n", ans);
}


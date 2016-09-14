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

int v[105];
vector<int> ans[4];

int main () {
    int n;
    bool pos = false;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        if (v[i] > 0) pos = true;
    }
    int a, b;
    a = b = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) ans[3].pb (v[i]);
        else if (v[i] < 0) {
            if (a >= 0) ans[1].pb (v[i]), a = -1;
            else if (b < 0 || (!pos && b == 0)) {
                ans[2].pb (v[i]);
                if (b == 0) b = -1;
                else b = 1;
            } else ans[3].pb (v[i]);
        } else {
            if (b == 0) b = 1;
            ans[2].pb (v[i]);
        }
    }
    printf ("%d ", ans[1].size ());
    for (int i = 0; i < ans[1].size (); i++) printf ("%d ", ans[1][i]);
    printf ("\n%d ", ans[2].size ());
    for (int i = 0; i < ans[2].size (); i++) printf ("%d ", ans[2][i]);
    printf ("\n%d ", ans[3].size ());
    for (int i = 0; i < ans[3].size (); i++) printf ("%d ", ans[3][i]);
    printf ("\n");
}


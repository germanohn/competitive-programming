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

vector<int> ans;

int main () {
    int n, k = 0, cont = 0;
    char s[105];
    scanf (" %d %s", &n, s);
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'W') {
            if (cont != 0) {
                k++;
                ans.pb (cont);
                cont = 0;
            }
        }
        else {
            cont++;
        }
    }
    if (cont != 0) {
        k++;
        ans.pb (cont);
    }

    printf ("%d\n", k);
    if (ans.size () == 0) return 0;
    for (int i = 0; i < ans.size (); i++) 
        printf ("%d ", ans[i]);
    printf ("\n");
}


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

char v[MAX];

int main () {
    int n, k;
    while (scanf ("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) 
            scanf (" %c", &v[i]);
        int l, r, aux, ans, ini;
        l = r = aux = 0;
        ini = -1;
        ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (v[i] != '*') {
                aux += v[i]-'0';
                if (r-l+1 == k) {
                    if (aux < ans) ans = aux, ini = l;
                    aux -= v[l]-'0', l++;
                }
                r++;
            } else {
                aux = 0, l = r = i+1;
            }
        }
        printf ("%d\n", ini == -1 ? 0 : ini+1);
    }
}


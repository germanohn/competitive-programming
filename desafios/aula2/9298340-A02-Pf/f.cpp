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

const int MAX = 10005;
const int MAXN = 15005;

int v[MAX], resto[MAXN], acc[MAX];

int main () {
    int n, l, r = -1;
    scanf ("%d", &n);
    acc[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        acc[i+1] = (acc[i] + v[i]) % n;
        if (acc[i+1] == 0) l = 0, r = i; 
    }
    if (r == -1) {
        for (int i = 0; i < n; i++) {
            if (resto[acc[i+1]] != 0) {
                l = resto[acc[i+1]];
                r = i;
                break;
            } else {
                resto[acc[i+1]] = i+1;
            }
        }
    }
    printf ("%d\n", r-l+1);
    for (int i = l; i <= r; i++)
        printf ("%d\n", v[i]);
}


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

int v[MAX], freq[MAX];

int main () {
    int n, q;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        freq[v[i]]++;
    }
    sort (v, v+n);
    scanf ("%d", &q);
    for (int i = 0; i < q; i++) {
        int val;
        scanf ("%d", &val);
        int pos = lower_bound (v, v+n, val)-v;
        if (v[pos] == val) {
            pos += freq[val];
            printf ("%d\n", pos);
        }
        else printf ("%d\n", pos);
    }
}


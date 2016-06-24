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

const int MAX = 1e5+5;

int n, ans;
int v[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    sort (v, v+n);
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > ans) 
            ans++;
    }
    printf ("%d\n", ans+1);
}


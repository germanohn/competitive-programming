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

const int MOD = 1000000007;

int main () {
    int n, m, ans;
    scanf ("%d %d", &n, &m);
    ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + n % i) % MOD;
        printf ("i %d ans %d\n", i, ans); 
    }
}


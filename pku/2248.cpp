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

int n;

void solve (int i) {
    if (ans[i-1] == n) return 0;
    int qtd_steps = INT_MAX;
    for (int r = i-1; r >= 0; r--) {
        for (int l = r; l >= 0; l--) {
            int nx = ans[l]+ans[r];
            if (nx < ans[i-1]) break;
            ans[i] = ans[l]+ans[r];
            qtd_steps = min (qtd_steps, 1 + solve (i+1));
        }
    }
    return qtd_steps;
}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        ans[0] = 1;
        solve (1);       
    }
}


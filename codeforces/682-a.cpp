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

ll freqN[10], freqM[10];

int main () {
    int n, m;
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        freqN[i%5]++;
    }
    for (int i = 1; i <= m; i++) {
        freqM[i%5]++;
    }
    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += (ll) freqN[i]*freqM[(5-i)%5];
    }
    cout << ans << "\n";
}


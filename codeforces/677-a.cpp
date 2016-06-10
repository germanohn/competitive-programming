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

int n, h, ans;

int main () {
    scanf ("%d %d", &n, &h);
    int ans = 0, a;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        if (a <= h)
            ans++;
        else if (a > h)
            ans += 2;
    }
    printf ("%d\n", ans);
}


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

int n, c;

int main () {
    scanf (" %d %d", &n, &c);
    int a, b, ans = 1;
    scanf (" %d", &a);
    for (int i = 1; i < n; i++) {
        scanf (" %d", &b);
        if (b-a <= c) ans++;
        else ans = 1;
        a = b;
    }
    printf ("%d\n", ans);
}


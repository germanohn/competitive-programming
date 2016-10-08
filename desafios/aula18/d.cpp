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

const int MAX = 1000005;

int n;
int appear[MAX], me[MAX], v[MAX];

int dp (int ult) {
    if (me[ult] != -1) return me[ult];

    int ans = 0;
    for (int j = 2; j * ult <= 1000000; j++) {
        if (appear[j * ult]) 
            ans = max (ans, 1 + dp (j * ult));    
    }

    return me[ult] = ans;
}

int main () {
    scanf (" %d", &n);
    memset (me, -1, sizeof me);
    for (int i = 0; i < n; i++) {
        scanf (" %d", &v[i]);
        appear[v[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) { 
        int val = dp (v[i]);
        ans = max (ans, 1 + val);
    }

    printf ("%d\n", ans);
}


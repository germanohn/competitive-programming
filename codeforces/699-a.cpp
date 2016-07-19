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

const int MAX = 200005;

int n;
char dir[MAX];
int v[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf (" %c", &dir[i]);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    int ans = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        if (dir[i] == 'R' && dir[i+1] == 'L') 
            ans = min (ans, (v[i+1]-v[i])/2);
    }
    if (ans == INT_MAX) printf ("-1\n");
    else printf ("%d\n", ans);
}


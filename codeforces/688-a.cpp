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

const int MAX = 105;

int n, d;
char pre;
int v[MAX];

int main () {
    scanf ("%d %d", &n, &d);
    for (int i = 0; i < d; i++) {
        bool f = true;
        for (int j = 0; j < n; j++) {
            scanf (" %c", &pre);
            if (pre == '0')
                f = false;
        }
        if (!f)
            v[i] = 0;
        else 
            v[i] = 1;
    }
    
    int ans = INT_MIN, tmp = 0;
    for (int i = 0; i < d; i++) {
        if (v[i] == 1) {
            ans = max (ans, tmp);
            tmp = 0;
        } else {
            tmp++;
        }
    }
    ans = max (ans, tmp);
    printf ("%d\n", ans);
}


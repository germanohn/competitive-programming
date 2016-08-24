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

const int MAX = 35;

int n;
int ans[MAX], p[MAX];

void print () {
    for (int j = 0; j < n-1; j++) printf ("%d ", ans[j]);
    printf ("%d\n", ans[n-1]);
}

bool back (int i, int mask) {
    if (i == n) {
        int num = ans[n-1]+ans[0];
        if (!p[num]) {
            print ();
            return true;
        } else {
            return false;
        }
    }
    bool ok = false;
    for (int j = 1; j < n; j++) {
        if (((1 << j) & mask) == 0) {
            int a = ans[i-1]+j+1;
            if (!p[a]) { 
                ans[i] = j+1;
                ok = back (i+1, (mask | (1 << j)));
            }
        }
    }
    return ok;
}

void sieve () {
    for (int i = 2; i < MAX; i++) 
        if (!p[i]) 
            for (int j = i+i; j < MAX; j += i) 
                p[j] = i;
}

int main () {
    int t = 1;
    sieve ();
    ans[0] = 1;
    bool f = false;
    while (scanf ("%d", &n) != EOF) {
        if (f) printf ("\n");
        f = true;
        printf ("Case %d:\n", t++);
        back (1, (1 << 0));
    }
}


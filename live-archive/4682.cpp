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

const int MAX = 5e6+5;

int t, n, ans, k;
int xorAcc[MAX], trie[MAX][3];

void add (int val) {
    int v = 0;
    for (int i = 30; i >= 0; i--) {
        if (trie[v][((val >> i) & 1)] == 0)
            trie[v][((val >> i) & 1)] = k++;
        v = trie[v][((val >> i) & 1)];
    }
}

void dfs (int val) {
    int v = 0, x = 0;
    for (int i = 30; i >= 0; i--) {
        if (trie[v][!((val >> i) & 1)] != 0) 
            v = trie[v][!((val >> i) & 1)], x |= ((1 << i));
        else 
            v = trie[v][((val >> i) & 1)];
    }
    ans = max (ans, x);
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        memset (trie, 0, sizeof trie);
        k = 1, ans = 0;
        scanf ("%d", &n);
        xorAcc[0] = 0;
        add (0);
        int a;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &a);
            xorAcc[i+1] = xorAcc[i] ^ a;
            add (xorAcc[i+1]);
            dfs (xorAcc[i+1]);
        }
        printf ("%d\n", ans);
    }
}

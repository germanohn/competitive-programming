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

const int MAX = 2e5;

int n, t, k;
int xorAcc[MAX], trie[MAX][3];

void add (int val) {
    int v = 0;
    for (int i = 17; i >= 0; i--) {
        if (trie[v][((val >> i) & 1)] == 0) 
            trie[v][((val >> i) & 1)] = k++;
        v = trie[v][((val >> i) & 1)];
    }
}

void dfs (int v) {
    int x = 0;
    for (int i = 0; i <= 1; i++) {
        if (trie[v][i] != 0)
           x += dfs (trie[v][i]); 
    }
    qtd[v] = x;
}

void traverse (int val, int idx) {
    if (idx < 0)
        return 1;
    int bitVal, bitK;
    bitVal = (val >> i) & 1;
    bitK = (val >> i) & 1;
    if (bitVal == bitK) {
        // entao tenho que ver 
    } else if (bitVal > bitK) {
        // entao tenho que ver 
        ans += qtd[trie[

    } else {
    
    }
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &a);
            xorAcc[i+1] = xorAcc[i] ^ a;
            add (xorAcc[i+1]);
        }
        
    }
}


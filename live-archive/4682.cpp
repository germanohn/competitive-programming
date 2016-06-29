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

int k, len;
int trie[MAX][15];


void add (int idx, int idxs) {
    if (len < 0) 
        return;
    if (trie[idx][v[idxs]] == 0) 
        trie[idx][v[idxs]] = k++;
    add (trie[idx][v[idxs]], idxs-1);
}

void convert (int a) {
    len = 0;
    while (a > 0) {
        bin[len++] = a % 2;
        a /= 2;
    }
}

void dfs (int idx) {
            
}

int main () {
    int t;
    while (t--) {
        memset (trie, 0, sizeof trie);
        k = 1, len = 0;
        scanf ("%d", &n);
        int acc = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &a);
            acc ^= a;
            convert (acc);
            add (0, len-1); 
        }
        dfs (len-1);
    }
}


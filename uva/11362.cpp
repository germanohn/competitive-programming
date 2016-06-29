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

const int MAX = 1e5+5;

int k, lenS;
int trie[MAX][15];
char s[15];

void add (int idx, int idxs) {
    if (idxs == lenS) 
        return;
    if (trie[idx][s[idxs]-'0'] == 0) 
        trie[idx][s[idxs]-'0'] = k++;
    add (trie[idx][s[idxs]-'0'], idxs+1);
}

int dfs (int idx) {
    bool isLeaf = true;
    int qtdLeaves = 0;
    for (int i = 0; i < 10; i++) {
        if (trie[idx][i]) {
            isLeaf = false;
            qtdLeaves += dfs (trie[idx][i]);
        }
    }
    return qtdLeaves + (isLeaf == true);
}

int main () {
    int t, n;
    scanf ("%d", &t);
    while (t--) {
        memset (trie, 0, sizeof (trie));
        k = 1; // quantidade de nós na trie
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf (" %s", s);
            lenS = strlen (s);
            add (0, 0);
        }
        int qtdPref = dfs (0);
        if (qtdPref == n) {
            printf ("YES\n");
        } else {
            printf ("NO\n");
        }
    }
}


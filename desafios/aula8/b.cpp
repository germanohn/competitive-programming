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

const int MAX = 1005;

int n;
int text[MAX];
char dic[MAX][20];

void solve (int i) {
    int changed[20], k = 0;
    for (int j = 0; j < n; j++) {
        if (len[j] == len_text[i]) {
            // agora vou ver se da match
            for (int l = 0; l < len[j]; l++) {
                int t = text[l]-'0', d = dic[j][l]-'0';
                if (!seen[t]) {
                    if (d
                } else {
                    
                }
            }     
        }
    }
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %s", dic[i]);
        len[i] = strlen (dic[i]);
    }
    while (scanf (" [^\n]s", line) != EOF) {
        char *aux = strtok (line, ' ');
        int k = 0;
        while (aux != NULL) {
            text[k] = aux;
            len_text[k++] = strlen (aux);
            aux = strtok (NULL, ' ');    
        }
        solve (0);
    }
}


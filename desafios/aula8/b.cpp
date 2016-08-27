#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
#define map coisa
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 1005;
const int MAXN = 256;

int n, len_line, k;
int len_dic[MAX], len_text[100];
bool seen[MAXN];
char line[100], map[MAXN];
char *text[100];
char dic[MAX][100];

bool solve (int i) {
    if (i == k) {
        for (int j = 0; j < k; j++) {
            if (j) printf (" ");
            for (int l = 0; l < len_text[j]; l++) 
                printf ("%c", map[text[j][l]]); 
        }
        printf ("\n");
        return true;
    }
    int ch[100], r = 0;
    for (int j = 0; j < n; j++) {
        if (len_dic[j] == len_text[i]) {
            r = 0;
            bool ok = true;
            for (int l = 0; ok && l < len_dic[j]; l++) {
                char t = text[i][l], d = dic[j][l];
                if (map[t] == 0) {
                    if (seen[d] != 0) {
                        ok = false;
                    } else {
                        map[t] = d;
                        seen[d] = 1;
                        ch[r++] = l;
                    }
                } else {
                    if (map[t] != d) ok = false; 
                }
            }     
            if (ok) 
                if (solve (i+1)) return true;
            for (int l = 0; l < r; l++) {
                char t = text[i][ch[l]];
                seen[dic[j][ch[l]]] = 0;
                map[t] = 0;
            }
        }
    }
    return false;
}

void init () {
    for (int i = 0; i < MAXN; i++) map[i] = 0, seen[i] = 0;
    k = 0;
}

int main () {

    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %s", dic[i]);
        len_dic[i] = strlen (dic[i]);
    }

    while (scanf (" %[^\n]", line) != EOF) {
        init ();
        len_line = strlen (line);
        char *aux = strtok (line, " ");
        while (aux != NULL) {
            text[k] = aux;
            len_text[k++] = strlen (aux);
            aux = strtok (NULL, " ");    
        }
        if (!solve (0)) {
            for (int i = 0; i < k; i++) {
                if (i) printf (" ");
                for (int j = 0; j < len_text[i]; j++) 
                    printf ("*");
            }
            printf ("\n");
        }
    }
}


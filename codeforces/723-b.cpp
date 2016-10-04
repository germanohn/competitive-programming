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

const int MAX = 260;

int main () {
    int n;
    char s[MAX];
    scanf ("%d %s", &n, s);
    
    bool has_par = 0, st_word = 0;
    int maior = 0, cont = 0, aux = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '(' || s[i] == ')' || s[i] == '_') {
            if (st_word) {
                if (has_par) {
                    cont++;
                } else {
                    if (aux > maior) maior = aux;
                }
            }
        }
        if (s[i] == '(') {
            has_par = 1;
            st_word = false;
            aux = 0;
        } else if (s[i] == ')') {
            has_par = 0;
            st_word = false;
            aux = 0;
        } else if (s[i] == '_') {
            st_word = false;
            aux = 0;
        } else {
            if (!st_word) st_word = true;
            aux++;
        }
    }
    
    if (st_word) {
        if (aux > maior) maior = aux;
    }

    printf ("%d %d\n", maior, cont);
}


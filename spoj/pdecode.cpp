#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

// decomposicao de permutacao em ciclos
int n, m;
// pai[i] é o lugar que o caracter na posicao i da string se encontra apos uma operacao
int pai[85];
char s[85], novo[85];
bool seen[85];

int main () {
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) 
            seen[i] = false;
        int a;
        for (int i = 0; i < n; i++) { 
            scanf ("%d", &a);
            a--;
            pai[a] = i;
        }
        // cuidado com scanf, se colocasse scanf nao passava
        /*scanf (" %[^\n]", s);*/
        getchar ();
        gets (s);
        int qOp, tam, nx, ini, fim;
        // como pai[i] é o lugar que o caracter na posicao i da string se encontra apos uma operacao
        // entao pra cada caractere i de 0 a n-1 (chamarei ele de ini) e pego pai[ini] qOp vezes.
        // ao final disso terei o lugar que o caractere na posicao ini (novo[ini]) deve estar, logo
        // s[fim] = novo[ini];
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                seen[i] = true;
                tam = 1;
                ini = nx = i;
                while (pai[nx] != i) {
                    tam++;
                    nx = pai[nx];
                    seen[nx] = true;
                }
                qOp = tam - m%tam;
                fim = ini;
                strcpy (novo, s);
                for (int j = 0; j < qOp; j++) 
                    fim = pai[fim];
                while (tam--) {
                    s[fim] = novo[ini];
                    fim = pai[fim];
                    ini = pai[ini];
                }
            }
        }
        printf ("%s\n", s);
    }
}


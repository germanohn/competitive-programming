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

const int MAX = 2005;

char pattern[30];

int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < 26; i++) 
        pattern[i] = 'a'+i;
    /*for (int i = 0; i < 26; i++)
        printf ("%c", pattern[i]);
    printf ("\n");*/
    for (int i = 1; i <= n; i++) {
        int qtd = i;
        printf ("%d : ", qtd);
        if ((qtd == 1 && n != 1) || (qtd == 2 && n != 2)) {
            printf ("NO\n");
        } else {    
            int done = 0;
            char a = 'a';
            while (qtd > 26) {
                putchar (a);
                qtd--;
                done++;
            }
            int end = n-done;
            for (int j = 0; j < end; j++) {
                putchar (pattern[j%qtd]);
            }
            printf ("\n");
        }
    }
}


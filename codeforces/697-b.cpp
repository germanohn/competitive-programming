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


int main () {
    char s[200];
    int a, cont = 0;
    scanf (" %d.%s", &a, s);
    int len = strlen (s), pot = 1, i, j;
    bool f = false;
    for (i = 0; i < len; i++) {
        if (f) 
            cont = cont*pot + s[i]-'0', pot *= 10; 
        if (s[i] == 'e') {
            j = i;
            f = true;
        }
    }
    len = j;
    printf ("%d", a);
    for (i = 0; i < cont; i++) {
        if (i >= len) {
            printf ("0");
        } else {
            printf ("%c", s[i]);
        }
    }
    if ((i == len-1 && s[i] == '0') || (len <= cont))
        printf ("\n");
    else {
        printf (".");
        for (; i < len; i++) 
            printf ("%c", s[i]);
        printf ("\n");
    }
}


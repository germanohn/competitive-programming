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

char s[MAX];
char ans[2*MAX];

int main () {
    scanf (" %s", s);
    int k = 0;
    for (int i = 0; s[i] != 0; i++) {
        ans[k] = s[i];
        k++;
    }
    int len = strlen (s);
    for (int i = len-1; i >= 0; i--) {
        ans[k] = s[i];
        k++;
    }
    printf ("%s\n", ans);
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 100005;

int n, k;
char s[MAX];

int main () {
    scanf ("%d %d", &n, &k);
    scanf ("%s", s);

    // Achar a maior sequencia com k b's
    int contB = 0, ans = 0, j = -1;
    for (int i = 0; i < n && j < n; i++) {
        while (contB <= k && ++j < n)
            if (s[j] == 'b')
                contB++;
        ans = max (ans, j-i);
        if (s[i] == 'b') 
            contB--;
    }

    int contA = 0;
    j = -1;
    for (int i = 0; i < n && j < n; i++) {
        while (contA <= k && ++j < n)
            if (s[j] == 'a')
                contA++;
        ans = max (ans, j-i);
        if (s[i] == 'a')
            contA--;
    }

    printf ("%d\n", ans);
}

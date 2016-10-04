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

const int MAX = 105;

int main () {
    int n, v[MAX];
    char s[MAX];
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        scanf (" %[^\n]s", s);
        int cont = 0;
        for (int j = 0; s[j] != 0; j++) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o'
                || s[j] == 'u' || s[j] == 'y')
               cont++; 
        }
        if (cont != v[i]) ok = false;
    }

    if (ok) printf ("YES\n");
    else printf ("NO\n");
}


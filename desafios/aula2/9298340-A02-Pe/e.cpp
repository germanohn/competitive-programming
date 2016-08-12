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

char s[105];
vector<int> divi;

int main () {
    for (int i = 0; i < 1000; i++) 
        if (i % 8 == 0) divi.pb (i);
    scanf (" %s", s);
    int len = strlen (s), ans = -1;
    bool ok = false;
    for (int i = 0; !ok && i < divi.size (); i++) {
        int num = divi[i], l = len-1, aux = num;
        bool found = true;
        do {
            int nx = aux % 10;
            aux /= 10;
            found = false;
            //printf ("aux %d\n", aux);
            for (int i = l; !found && i >= 0; i--) 
                if (s[i]-'0' == nx) l = i-1, found = true;
        } while (found && aux > 0);
        if (aux == 0 && found) ok = true, ans = num;
    }
    if (ans == -1) printf ("NO\n");
    else printf ("YES\n%d\n", ans);
}


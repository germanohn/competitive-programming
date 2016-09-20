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

const int MAX = 500005;

char s[MAX], falta[200];
set<char> pal;

int main () {
    scanf (" %s", s);
    int l, r, k = 0;
    bool ok = false;
    l = 0;
    for (int i = 0; !ok && s[i] != 0; i++) {
        if (s[i] != '?') {
            if (pal.find (s[i]) == pal.end ()) {
                pal.insert (s[i]);
                if (pal.size () == 26) {
                    r = i;
                    ok = true;
                }   
            } else {
                pal.clear ();
                pal.insert (s[i]);
                l = i;
            }
        }
        if (i-l+1 == 26) r = i, ok = true;
    }


    for (char i = 'A'; i <= 'Z'; i++) {
        if (pal.find (i) == pal.end ()) 
            falta[k++] = i;
    }
    if (ok) {
        int cont = 0;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] == '?') {
                if (i >= l && i <= r) {
                    s[i] = falta[cont++]; 
                } else {
                    s[i] = 'A';
                }
            }
        }
        printf ("%s\n", s);
    } else {
        printf ("-1\n");
    }
}


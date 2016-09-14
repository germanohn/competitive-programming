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

const int MAX = 1000005;

int z[MAX];
char s[MAX];

void z_function () {
    int l = 0, r = 0;
    int n = strlen (s);
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r] == s[r-l]) r++;
            z[i] = r-l, r--;
        } else {
            int k = i-l;
            if (z[k] < r-i+1) z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r] == s[r-l]) r++;
                z[i] = r-l, r--;
            }
        }
    }
}   

int main () {
    scanf (" %s", s);
    z_function ();
    int n = strlen (s), maior = -1, ans = -1;
    for (int i = 1; i < n; i++) {
        if (z[i] + i == n && maior >= z[i]) {
            ans = i;
            break;
        }
        maior = max (maior, z[i]);
    }
    if (ans != -1) {
        for (int i = ans; i < n; i++) 
            printf ("%c", s[i]);
        printf ("\n");
    } else {
        printf ("Just a legend\n");
    }

}


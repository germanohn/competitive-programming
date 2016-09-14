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

const int MAX = 5000005;
const int MAXN = 10000000;

int z[MAXN];

void z_function (char s[]) {
    int len = strlen (s);
    int l = 0, r = 0;
    for (int i = 1; i < len; i++) {
        if (i > r) {
            l = r = i;
            while (r < len && s[r] == s[r-l]) r++;
            z[i] = r-l, r--;
        } else {
            int k = i-l;
            if (z[k] < r-i+1) z[i] = z[k];
            else {
                l = i;
                while (r < len && s[r] == s[r-l]) r++;
                z[i] = r-l, r--;
            }
        }
    }
}

int main () {
    int len_pattern;
    char text[MAX];
    bool f = false;
    while (scanf (" %d", &len_pattern) != EOF) {
        if (f) printf ("\n");
        f = false;
        scanf (" %s", text);
        len_pattern = strlen (text);
        text[len_pattern] = '$';
        scanf (" %s", text+len_pattern+1);
        int len = strlen (text);

        z_function (text);

        for (int i = 1; i < len; i++) { 
            if (z[i] == len_pattern) {
                printf ("%d\n", i-len_pattern-1);
                f = true;
            }
        }
    }
}


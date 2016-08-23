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

int z[MAX], n;
char s[MAX];

void z_function () {
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        z[i] = 0;
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

bool ok (int len) {
    bool f = true;
    for (int i = len; f && i < n; i++) 
        if (s[i] != s[i%len]) f = false;
    return f;
}

int main () {
    while (scanf (" %s", s) && s[0] != '.') {
        n = strlen (s);
        z_function ();
        z[0] = n;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (z[i] != 0 && (n % z[i]) == 0 && (n/z[i]) > ans && ok (z[i])) 
                ans = n/z[i];
        }
        printf ("%d\n", ans);
    }
}


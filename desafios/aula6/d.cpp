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

const int MAX = 5123456;

int z[MAX], n, pref[MAX];
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

void sieve () {
    for (int i = 0; i < n; i++) {
        int step = i+1;
        for (int j = step; j < n; j += step) {
            int pref_end = j+step-1;
            if (z[j] >= step) pref[pref_end] = min (pref[pref_end], step);
            else break;
        }
    }
}

int main () {
    int t;
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        scanf ("%d %s", &n, s);
        for (int i = 0; i < MAX; i++) pref[i] = i+1;
        z_function ();
        sieve ();
        printf ("Test case #%d\n", cont++);
        for (int i = 0; i < n; i++) 
            if (pref[i] < i+1) printf ("%d %d\n", i+1, (i+1)/pref[i]);
        printf ("\n");
    }
}


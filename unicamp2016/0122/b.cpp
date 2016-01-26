#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAX 200005
using namespace std;
typedef pair<int, int> pii;

char s[MAX];
pii pos[MAX];

int main () {
    scanf (" %s", s);
    int k = 0, n = strlen (s), um = 0;
    bool f = false;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '1') {
            if (f) pos[k++].ss = i;
            else f = true, pos[k].ff = i;
            pos[k].ff = i;
            um++;
        }
    }
    pos[k].ss = n;
    /*for (int i = 0; i <= k; i++) {
        printf ("ff %d ss %d\n", pos[i].ff, pos[i].ss);
    }*/

    int mi = INT_MAX;
    for (int i = 0; i <= k; i++)
        mi = min (mi, min (2*pos[i].ff + n - pos[i].ss, 2*(n-pos[i].ss) + pos[i].ff));
    printf ("%d\n", mi*7 + 4*um);
}

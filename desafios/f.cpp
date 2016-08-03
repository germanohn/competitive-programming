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

const int MAX = 100005;

int main () {
    int n, k;
    char ans[MAX], s[MAX];
    scanf ("%d %d %s", &n, &k, s);
    for (int i = 0; s[i] != 0; i++) {
        int pos = s[i]-'a';
        if (25-pos > pos) {
            if (k > 25-pos) {
                ans[i] = 'z';
                k -= (25-pos);
            } else {
                ans[i] = pos+k+'a';
                k = 0;
            }
        } else {
            if (k > pos) {
                ans[i] = 'a';
                k -= pos;
            } else {
                ans[i] = pos-k+'a';
                k = 0;
            }
        }
    }
    if (k == 0) printf ("%s\n", ans);
    else printf ("-1\n");
}


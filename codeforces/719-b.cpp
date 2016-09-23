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

char s[MAX];

int main () {
    int n, q_r = 0, q_b = 0;
    scanf (" %d %s", &n, s);
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'r') 
            q_r++;
        else 
            q_b++;
    }    

    char c;
    int q_imp, q_par, q, cont = 0;
    int ans;
    if (q_r >= q_b)
        c = 'r', q = q_r;
    else 
        c = 'b', q = q_b;

    for (int i = 0; i < n; i += 2) {
        if (s[i] == c) 
            cont++;
    }
    q_imp = (n+1) / 2;

    int ans_imp = max (q - cont, q_imp - cont);

    cont = 0;
    for (int i = 1; i < n; i += 2) {
        if (s[i] == c)
            cont++;
    }   
    q_par = n/2;

    int ans_par = max (q - cont, q_par - cont);

    ans = min (ans_imp, ans_par);

    printf ("%d\n", ans);
}

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

const int MAX = 255;

char s[MAX];
int ans[MAX], k;

void solve (int l, int r, int qtd_less) {
    if (l >= r) return;
    int qtd_open, qtd_close, i = l+1;
    qtd_open = qtd_close = 0;

    for (; i < r; i++) {
        if (s[i] == '(') qtd_open++;
        else if (s[i] == ')') qtd_close++;

        else if (s[i] == ',' && qtd_open == 0) {
            i++;
            break;
        }   
        
        if (qtd_open != 0 && qtd_open == qtd_close) 
            break;
    }

    if (qtd_open == 0) {
        ans[k++] = qtd_less + 1;
    } else {
        ans[k++] = qtd_open + qtd_less + 1;
    }

    l = l+1;
    while (s[l] != '(' && l <= i) l++;
    solve (l, i, qtd_less);

    while (s[i] != '(' && i <= r-1) i++;
    solve (i, r-1, qtd_less + 1 + qtd_open);
}   

int main () {
    while (scanf (" %s", s)) {
        if (s[0] == '(' && s[1] == ')') 
            break;
        k = 0;

        solve (0, strlen (s) - 1, 0);

        for (int i = 0; i < k-1; i++)  
            printf ("%d ", ans[i]);
        printf ("%d\n", ans[k-1]);
    }
}


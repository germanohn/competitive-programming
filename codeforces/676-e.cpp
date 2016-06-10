#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MAX = 100005;

int n, k;
char v[MAX][10];

// temos tres casos pra esse problema: 
// k == 0, qtdInt == 0, e k != 0 && qtdInt != 0
int main () {
    scanf ("%d %d", &n, &k);
    int qtdInt;
    ll sum;
    bool humanWin, divisivel;
    qtdInt = 0, humanWin = false, sum = 0, divisivel = true;
    for (int i = 0; i <= n; i++) {
        scanf (" %s", v[i]);
        if (v[i][0] == '?')
            qtdInt++;
        else if (k != 0 && divisivel && qtdInt == 0) {
            ll num = atoi (v[i]);
            if ((sum + num) % abs (k) == 0) {
                sum = (ll) (sum + num)/k; 
            } else {
                divisivel = false;
            }
        }
    }
    
    if (k == 0) {
        if (v[0][0] == '0') { 
            humanWin = true;
        } else if (v[0][0] == '?') {
            // tem que ver quem joga primeiro
            if ((n+1 - qtdInt) % 2 != 0) {
                humanWin = true;
            } else {
                humanWin = false;
            }
        } else { 
            humanWin = false;
        }
    } else if (qtdInt == 0) {
        if (divisivel && sum == 0)
           humanWin = true;
        else
           humanWin = false; 
    } else {
        // tenho que ver quem comeca pra ver quem é o ultimo a jogar
        bool stHuman = false;
        if ((n+1 - qtdInt) % 2 != 0)
            stHuman = true;
        else 
            stHuman = false;
        
        if (stHuman) {
            if (qtdInt % 2 != 0)
                humanWin = true;
            else 
                humanWin = false;
        } else {
            if (qtdInt % 2 != 0) 
                humanWin = false;
            else
                humanWin = true;
        }
        
    }

    if (humanWin)
        printf ("Yes\n");
    else 
        printf ("No\n");
}

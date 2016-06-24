#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
char str[100];

int dp2 (int i, bool pre, int mask) {
    if (i == lenM) {
        return 0;
    }       
    if (me2[i][pre][mask] != -1) return me[i][pre][mask];
    for (int dig = 0; dig <= 6; dig++) {
        if (pre && dig > str[i]-'0') 
            break;
        if ((mask & (1 << dig)) > 0)
            continue;
        if ans += dp (i+1, pre && (dig == str[i] - '0'), mask | (1 << dig);
    }
    return ans;
}

int dp (int i, bool pre, int mask) {
    if (i == lenH) {
        return dp2 (0, 0, mask);    
    }
    if (me[i][pre][mask] != -1) return me[i][pre][mask];
    for (int dig = 0; dig <= 6; dig++) {
        if (pre && dig > str[i]-'0') 
            break;
        if ((mask & (1 << dig)) > 0)
            continue;
        if ans += dp (i+1, pre && (dig == str[i] - '0'), mask | (1 << dig);
    }
    return ans;
}



int main () {
    scanf ("%d %d", &n, &m);
    int qtdH, qtdM;
    qtdH = (n+6)/7;
    qtdM = (m+6)/7;
    if (qtdH+qtdM > 7) {
        printf ("0\n");
    } else {
        // tenho que construir o maior numero 
        int maiorH, aux, pot = 1;
        aux = n;
        for (int i = 0; i < qtdH; i++) 
            pot *= 7;
        int num = 0;
        while (aux > 0) {
            for (int i = 1; i <= 6; i++) {
                if (i*pot > aux)
                    break;
                num[i] = 
                num += i*pot;
            }
            aux
        }
    }
} 

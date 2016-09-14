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

const int MAX = 600005;
const int MAXN = 100005;

int t;
int freq[MAX];
char num[MAXN][20];
char sinal[MAXN];

int main () {
    scanf ("%d", &t);
    int tam = 0;
    for (int i = 0; i < t; i++) {
        scanf (" %c %s", &sinal[i], num[i]);
        int len = strlen (num[i]);
        tam = max (tam, len); 
    }
    
    for (int i = 0; i < t; i++) {
        int aux = tam;
        int len = strlen (num[i])-1;
        int val = 0, pot = 1;
        while (aux--) {
            if (len >= 0) {
                if ((num[i][len]-'0') % 2 == 0) 
                    val += pot;    
                len--;
            } else {
                val += pot;
            }
            pot *= 2;
        }   
       
        if (sinal[i] == '+') freq[val]++;
        else if (sinal[i] == '-') freq[val]--;
        else printf ("%d\n", freq[val]);
    }
}


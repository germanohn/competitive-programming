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

const int MAX = 1005;
    
int n;
int bus[MAX][10];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf (" %c", &bus[i][j]);
        }
    }
    bool ans = false;
    for (int i = 0; !ans && i < n; i++) {
        if (bus[i][0] == 'O' && bus[i][1] == 'O')
            bus[i][0] = '+', bus[i][1] = '+', ans = true;
        else if (!ans && bus[i][3] == 'O' && bus[i][4] == 'O')
            bus[i][3] = '+', bus[i][4] = '+', ans = true;
    }
    if (ans) {
        printf ("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) 
                printf ("%c", bus[i][j]);
            printf ("\n");
        }
    } else {
        printf ("NO\n");
    }
}


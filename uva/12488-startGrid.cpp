#include <bits/stdc++.h>
using namespace std;

int n, ans, x; 
int posIni[50];
int posFim[50];

int main () {
    while (scanf ("%d", &n) != EOF) {
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &x);
            posIni[x] = i;
        }
        for (int i = 0; i < n; i++) {
            scanf ("%d", &posFim[i]);
        }
        /* agora pra cada cara desde o primeiro na posicao final vou ver quantos vinham antes dele
        // na largada*/
        for (int i = 0; i < n; i++) {
            x = posIni[posFim[i]];//posicao que o primeiro no final ocupava na largada
            // agora vou ver pra todos depois de x se vinham antes que x na largada. se sim conto como ultrapassagem
            for (int j = i + 1; j < n; j++) {
                if (posIni[posFim[j]] < x) ans++;
            }
        }
        printf ("%d\n", ans);
    }
}

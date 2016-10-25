#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e8;
const int MAX = 505;

int n, k, ans;
int v[MAX], b[MAX];
int me[MAX][2*MAX];

int dp(int i, int val_ant) {
    if (i == n) return 0;
    if (me[i][val_ant] != -1) return me[i][val_ant];

    int aux = inf;
    for (int up = 0; up <= k; up++) { 
        if (i == 0 || (v[i] + up + val_ant >= k)) 
            aux = min(aux, up + dp(i + 1, v[i] + up));
    }

    return me[i][val_ant] = aux;
}

void construct(int i, int val_ant, int acc) {
    if(i == n) return;

    int aux;
    for (int up = 0; up <= k; up++) {
        //printf("i %d up %d v[i] %d\n", i, up, v[i]);
        if (i == 0 || (v[i] + up + val_ant >= k)) { 
            //printf("up %d\n", up);
            aux = dp(i + 1, v[i] + up);
            //printf("aux %d acc %d entrei i %d up %d v[i] %d\n", aux, acc, i, up, v[i]);
            if (aux + up + acc == ans) {
         //       printf("i %d up %d\n", i, up);
                b[i] = v[i] + up;
                construct(i + 1, b[i], acc + up);
                break;
            }
        }
    }
}

int main () {
    scanf("%d %d", &n, &k);
    memset(me, -1, sizeof me);
    for (int i = 0; i < n; i++) 
        scanf("%d", &v[i]);

    ans = dp(0, k);
    construct(0, k, 0);

    printf("%d\n", ans);
    for (int i = 0; i < n; i++) 
        printf("%d ", b[i]);
    printf("\n");
}


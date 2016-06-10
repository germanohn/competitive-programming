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

const int MAX = 15;
const double eps = 1e-8;

int n, t;
double py[MAX][MAX];
int ans;

int main () {
    scanf ("%d %d", &n, &t);
    while (t--) {
        py[0][0] += 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (py[i][j] > 1-eps) { 
                    double fora = py[i][j] - 1;
                    py[i+1][j] += fora/2;
                    py[i+1][j+1] += fora/2;
                    py[i][j] -= fora;
                }   
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (py[i][j] >= 1)
                ans++;
        }
    }
    printf ("%d\n", ans);
}


#include <bits/stdc++.h>
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

const int MAX = 105;

int n, d, a;
int pai[MAX], peso[MAX];
char rta[MAX][MAX], A[MAX][MAX];
vector<pii> adj;

int find (int x) {
    if (pai[x] == -1) return x;
    return pai[x] = find (pai[x]);
}

bool join (int x, int y) {
    x = find (x), y = find (y);
    if (x == y) return false;
    if (x < y) swap (x, y);
    pai[y] = x;
    peso[x] += peso[y];
    return true;
}

int main () {
    scanf ("%d%d%d", &n, &d, &a);//d: price to cancel the flight
    //a price to create a new flight
    int fly;
    for (int i = 0; i <= n; i++) {
        pai[i] = -1;
        peso[i] = 1;
    }
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = k; j < n; j++) {
            scanf (" %c", &A[i][j]);
            rta[i][j] = '0';
            if (A[i][j] == '1') {
                printf ("colocou i %d j %d\n", i, j);
                adj.pb (mp (i, j));
                adj.pb (mp (j, i));
                if (!join (x, y)) {
                    cost += d;
                    rta[x][y] = 'd';
                    rta[y][x] = 'd';
                }
            }
        }
        k++;
    }
    printf ("cost de tirar %d\n", cost);
    for (int i = 1; i < n; i++) {
        if (pai[i] == -1) {
            join (pai[0], pai[i]);
            cost += a;

        }
    }
    printf ("%d\n", cost);
    for (int i = 0; i< n; i++) {
        for (int j = 0; j < n; j++) {
            printf ("%c", rta[i][j]);
        }
        printf ("\n");
    }
}







#include <bits/stdc++.h>
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 105;

ll n, d, a;
int pai[MAX], peso[MAX];
char rta[MAX][MAX], A[MAX][MAX];


int find (int x) {
    if (pai[x] == -1) return x;
    return pai[x] = find (pai[x]);
}

bool join (int x, int y) {
    x = find (x), y = find (y);
    if (x == y) return false;
    if (peso[x] < peso[y]) swap (x, y);
    pai[y] = x;
    peso[x] += peso[y];
    return true;
}

int main () {
    scanf ("%lld%lld%lld", &n, &d, &a);//d: price to cancel the flight
    //a price to create a new flight
    int fly;
    for (int i = 0; i <= n; i++) {
        pai[i] = -1;
        peso[i] = 1;
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            rta[i][j] = '0';
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf (" %c", &A[i][j]);
            if (i < j) continue;
            if (A[i][j] == '1') {
                //printf ("colocou i %d j %d\n", i, j);
                if (!join (i, j)) {
                    cost += d;
                    rta[i][j] = 'd';
                    rta[j][i] = 'd';
                }
            }
        }
    }
    //printf ("cost de tirar %d\n", cost);
    int p = find (0), quant = 0;
    for (int i = 1; i < n; i++) {
        if (pai[i] == -1 && i != p) {
            quant++;
            rta[i][p] = 'a';
            rta[p][i] = 'a';
        }
    }
    cost += (quant) * a;
    printf ("%lld\n", cost);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf ("%c", rta[i][j]);
        }
        printf ("\n");
    }
}







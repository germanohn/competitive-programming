#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 25;

int n, m;
int v[MAX][MAX];

int main () {
    scanf (" %d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf ("%d", &v[i][j]);
            v[i][j]--;
        }
    }

    bool ans = false;
    for (int i = 0; !ans && i < m; i++) {
        for (int j = 0; !ans && j < m; j++) {

            ans = true;
            for (int row = 0; ans && row < n; row++) {
                int cont = 0;
                for (int col = 0; col < m; col++) {
                    if (col != i && col != j) {
                        if (col != v[row][col]) 
                            cont++;
                    }
                    if (col == i) {
                        if (v[row][col] != j) 
                            cont++;
                    } else if (col == j) {
                        if (v[row][col] != i) 
                            cont++;
                    }
                }
                if (cont > 2) ans = false;
            }
        }
    }

    if (ans) {
        printf ("YES\n");
    } else {
        printf ("NO\n");
    }
}

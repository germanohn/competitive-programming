#include <bits/stdc++.h>
#define pb push_back
#define MAX 100
using namespace std;

vector<set<int> > adj[MAX];
int tab[MAX][MAX];

int main () {
    int n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf ("%d", &tab[i][j]);
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;

            }
        }
    }
}


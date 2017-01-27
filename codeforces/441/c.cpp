#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, k;

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    int cont = 0;
    for (int i = 0; i < n; i++) {
        int st, inc;
        if (i % 2 == 0) 
            st = 0, inc = 1;
        else 
            st = m - 1, inc = -1;
        for (int j = st; (i % 2 == 0 && j < m) || (i % 2 == 1 && j >= 0); j += inc) {
            if (k > 1 && !cont) 
                printf("2 ");
            else if (k == 1 && !cont) {
                if (i % 2 == 0) printf("%d ", m - j + (n - i - 1) * m);
                else printf("%d ", j + 1 + (n - i - 1) * m);
            }
            printf("%d %d ", i + 1, j + 1);
            cont++;
            if (cont == 2 && k > 1) {
                cont = 0, k--;
                printf("\n");
            }
        }
    }
    printf("\n");
}


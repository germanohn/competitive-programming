#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int t, n, k, a;
int pai[MAX];

int parent (int x) {
    if (pai[x] == x) return x;
    return parent (pai[x]);
}

int main () {
    scanf ("%d", &t);
    int cont = 1;
    while (t--) {
        scanf ("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            int a;
            scanf ("%d", &a);
            if (a == 0) pai[i+1] = i+1;
            else
                pai[i+1] = a;
        }
        char c;
        printf ("Case #%d:\n", cont++);
        for (int i = 0; i < k; i++) {
            scanf (" %c", &c);
            if (c == 'Q') {
                int b;
                scanf ("%d %d", &a, &b);
                if (parent (a) == parent (b)) {
                    printf ("YES\n");
                }
                else {
                    printf ("NO\n");
                }
            }
            else {
                scanf ("%d", &a);
                pai[a] = a;
            }
        }
    }
}

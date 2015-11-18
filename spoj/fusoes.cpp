#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n, k, pai[MAX], w[MAX];


int find (int a) {
    if (a == pai[a]) return a;
    return pai[a] = find (pai[a]);
}

void join (int a, int b) {
    a = find (a), b = find (b);
    if (a != b) {
        if (w[a] < w[b]) swap (a, b);
        pai[b] = a;
        w[a] += w[b];
    }
}

int main () {
    scanf ("%d %d", &n, &k);
    int a, b;
    for (int i = 1; i <= n; i++) {
        pai[i] = i;
        w[i] = 1;
    }
    char c;
    for (int i = 0; i < k; i++) {
        scanf (" %c %d %d", &c, &a, &b);
        if (c == 'C') {
            if (find (a) == find (b)) 
                printf ("S\n");
            else printf ("N\n");
        }
        else {
            join (a, b);
        }
    }
}

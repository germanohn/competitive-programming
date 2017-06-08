#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;

int n, m;
int p[N];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &p[i]);
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf(" %d %d %d", &l, &r, &x);
        l--, r--, x--;
        int pos = x - l;
        int cont = 0;
        for (int i = l; i <= r; i++) {
            if (p[i] < p[x])
                cont++;
        }

        if (cont == pos) printf("Yes\n");
        else printf("No\n");
    }
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main () {
    int k, l, m, n, d;
    scanf(" %d %d %d %d %d", &k, &l, &m, &n, &d);

    int cont = 0;
    for (int i = 1; i <= d; i++) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            cont++;
    }

    printf("%d\n", cont);
}


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 12;

int n, b;
ll x, y, vx[MAX], vy[MAX];

int main () {
    cin >> n >> b; 
    for (int i = 0; i < n; i++) {
        cin >> vx[i];
    }
    ll pot = 1;
    for (int i = n-1; i >= 0; i--) {
        x += vx[i]*pot;
        pot *= b;
    }
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> vy[i];
    }
    pot = 1;
    for (int i = n-1; i >= 0; i--) {
        y += vy[i]*pot;
        pot *= b;
    }
    if (x == y) printf ("=\n");
    else if (x < y) printf ("<\n");
    else printf (">\n");
}

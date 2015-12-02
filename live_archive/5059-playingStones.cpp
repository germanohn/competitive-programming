#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 105;

ll v[MAX];

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n; 
        scanf ("%d", &n);
        ll grun = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%lld", &v[i]);
            while (v[i] % 2 != 0) {
                v[i] /= 2;
            }
            if (v[i] % 2 == 0)
                v[i] /= 2;
        }
        grun = v[0];
        for (int i = 1; i < n; i++) {
            grun ^= v[i]; 
        } 
        if (grun == 0) printf ("NO\n");
        else printf ("YES\n");
    }
}

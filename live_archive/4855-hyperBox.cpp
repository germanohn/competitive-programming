#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 20;
const int MAX = 2000000000;

int t, n, v[MAXN];
ll f[100], me[100];

ll fib (int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    ll &m = me[n];
    if (m != -1) return m;
    m = fib (n-1) + fib (n-2);
    return m;
}

int main () {
    int k = 2;
    f[0] = 0, f[1] = 1;
    memset (me, -1, sizeof (me));
    ll num = 0;
    while (num < MAX) {
        f[k] = fib (k);
        num = f[k];
        k++; 
    } 
    scanf ("%d", &t);
    int cont = 1;
    while(t--) {
        scanf ("%d", &n);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            int num = v[i], aux = 0;
            while (num != 0) {
                for (int i = 1; i < k; i++) {
                    if (f[i] > num) {
                        num -= f[i-1];
                        aux++;
                        break;
                    }
                }
            }
            ans *= aux;
        }
        printf ("Case %d: %d\n", cont++, ans);
        
    }
}

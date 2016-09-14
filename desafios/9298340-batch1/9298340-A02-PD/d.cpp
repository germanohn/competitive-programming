#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 1000004;
const int MAX = 1000000000;

ll pot[MAXN];

int main() {
    int n, k, ans = 0;
    scanf ("%d %d", &n, &k);
    ll acc = 1;
    int cont = 0;
    bool f = false;
    while (!f) {
        if (acc > MAX) f = true;
        pot[cont++] = acc;
        acc *= 2;
    }
    int pos = lower_bound (pot, pot+cont, k)-pot;
    if (k == pot[pos]) pos++;
    if (n <= pot[pos]) {
        //printf ("oi\n");
        for (int i = 0; i < cont; i++) {
            if (pot[i] >= n) {
                ans = i;
                break;
            }
        }    
    } else {
        ans += pos;
        n -= pot[pos];
        if (n % k == 0) ans += n/k;
        else ans += n/k + 1;
    }
    printf ("%d\n", ans);
}


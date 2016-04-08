#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 50005;
const int MAXN = 1000005;

int c, d, n;
ll acc[MAX], res[MAXN];

int main () {
    scanf ("%d", &c);
    while (c--) {
        scanf ("%d %d", &d, &n);
        for (int i = 0; i < n; i++) 
            scanf ("%lld", &acc[i]);
        for (int i = 0; i < d; i++) 
            res[i] = 0;
        acc[0] %= d;
        res[acc[0]]++;
        for (int i = 1; i < n; i++) {
            acc[i] = (acc[i] + acc[i-1]) % d;
            res[acc[i]]++;
        }
        ll ans = res[0];
        for (int i = 0; i < d; i++) 
            ans += (res[i] * (res[i]-1)) / 2;
        printf ("%lld\n", ans);
    }
}


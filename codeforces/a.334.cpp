#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 10;

ll ti[MAX], wa[MAX], a, b; 
ll sco[MAX];

int main () {
    sco[1] = 500;
    for (int i = 2; i <= 5; i++) {
        sco[i] = sco[i-1] + 500; 
    }
    for (int i = 1; i <= 5; i++) 
        scanf ("%I64d", &ti[i]);
    for (int i = 1; i <= 5; i++)
        scanf ("%I64d", &wa[i]);
    scanf ("%I64d %I64d", &a, &b);
    ll tot = 0;
    for (ll i = 1; i <= 5; i++) {
        ll aa, bb;
        aa = (250-ti[i])*sco[i]/250;
        bb = 3*sco[i]/10;
        tot += max (bb, aa - 50*wa[i]);      
    }
    tot = tot + 100*a - 50*b;
    printf ("%I64d\n", tot);
}

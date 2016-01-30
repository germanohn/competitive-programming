#include <bits/stdc++.h>
#define MAX 200005
#define MOD 1000000000+7
using namespace std;
typedef long long ll;

int m, p, num, q[MAX];
ll n;

ll fexp (int base, int exp) {
    if (exp == 1) return base;
    ll ans;
    if (exp % 2 != 0) 
        ans = base * pow (fexp (base, (exp-1)/2), 2);  
    else 
        ans = base * pow (fexp (base, exp/2), 2);
    return ans % MOD;
}

int main () {
    scanf ("%d", &m);
    n = 1;
    for (int i = 0; i < m; i++) 
        scanf ("%d", &p), q[p]++, n = (n * p)%MOD;
    int tmp;
    num = 1;
    for (int i = 0; i < m; i++)  
        tmp = q[i], num *= (tmp+1);
    printf ("num %d\n", num);
    ll ans = fexp (n, num/2);
    cout << ans << "\n";
}



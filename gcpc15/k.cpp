#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
int k;
char s[33];

bool isp(ll x) {
    if(x == 1) return false;
    int div = 0;
    for(ll d = 1; d*d <= x; d++)
        if(x % d == 0) div++;
    return div == 1;
}

int main() {
    scanf("%lld",&n);
    sprintf(s, "%lld", n);
    k = strlen(s);
    reverse(s, s+k);

    bool ok = isp(n);
    for(int i = 0; i < k; i++) {
        if(s[i] == '6') s[i] = '9';
        else if(s[i] == '9') s[i] = '6';
        else if(s[i] == '3' || s[i] == '4' || s[i] == '7') ok = false;
    }
    n = atoll(s);
    ok &= isp(n);
    puts(ok ? "yes" : "no");
}


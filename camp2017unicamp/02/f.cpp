#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    ll n;
    scanf("%lld",&n);
    if(n == 1) puts("WIN");
    else {
        ll i, p, q;
        q = 2;
        i = 2; p = 2;
        while(i <= n) {
            if(i == n) break;
            i += p;
            if(i >= q*q) {
                i++;
                p++;
                q++;
            }
        }
        if(i == n) puts("LOSE");
        else puts("WIN");
    }
}


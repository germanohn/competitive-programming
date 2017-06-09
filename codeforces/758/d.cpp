#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n;
char k[65];

int main() {
    scanf(" %lld %s", &n, k);

    int len = strlen(k);
    ll ten_pot = 1, pot = 1;
    ll cur = 0, ans = 0;
    for (int i = len - 1; i >= 0; i--) {
        ll dig = k[i] - '0';
        if (cur + (dig * ten_pot) < n) {
            cur += (dig * ten_pot);
            ten_pot *= 10;
        } else {
            ans += (cur * pot);
            
            if (cur != 0) 
                pot *= n;

            cur = dig, ten_pot = 10;

            for (int j = i + 1; j < len && k[j] == '0'; j++) {
                if (cur * 10 < n) {
                    cur *= 10;
                    ten_pot *= 10;
                } else {
                    pot *= n;
                }
            }
        }
    }
    ans += (cur * pot);
    
    printf("%lld\n", ans);
}

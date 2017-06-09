#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int k;
char s[MAX];

int main () {
    scanf(" %d %s", &k, s);
    int left = 0, l = 0, ones = 0;
    ll ans = 0;
    if (k) {
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] == '1') ones++;

            if (ones == k + 1) 
                left = 0, l++, ones--;
            if (ones == k) {
                if (!left) {
                    left = !!k;
                    while (s[l] != '1' && s[l] != 0 && l < i) l++, left++;
                }
                ans += (ll) left;
            }
        }
    } else {
        ll zeros = 0;
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] == '1') {
                ans += (zeros * (1 + zeros) / 2);
                zeros = 0;
            } else 
                zeros++;
        }
        ans += (zeros * (1 + zeros) / 2);
    }
    printf("%lld\n", ans);
}



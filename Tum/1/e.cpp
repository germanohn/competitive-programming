#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int p, len;
string s;

ll get_num() {
    ll ret = 0;
    while (p < len && s[p] >= '0' && s[p] <= '9') {
        ret = ret * 10 + (s[p] - '0');
        p++;
    }
    return ret;
}

char get_op() {
    if (s[p] == 'p' && s[p + 1] == 'l') { 
        p += 4;
        return '+';
    } else if (s[p] == 'm') { 
        p += 5;
        return '-';
    } else if (s[p] == 't' && s[p + 1] == 'i') { 
        p += 5;
        return '*';
    } 
    p += 12;
    return '^';
}

ll fexp(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e % 2) 
            ret *= b;
        e /= 2;
        b *= b;
    }
    return ret;
}

int main() {
    int t, test = 1;
    scanf(" %d ", &t);
    while (t--) {
        printf("Case #%d: ", test++);
        p = 0;
        cin >> s;
        len = s.length();
        ll ans = get_num();
        while (p < len) {
            char op = get_op();
            ll cur = get_num();
            if (op == '+') {
                ans += cur;
            } else if (op == '-') {
                ans -= cur;
            } else if (op == '*') {
                ans *= cur;
            } else {
                ans = fexp(ans, cur);
            }
        }
        printf("%lld\n", ans);
    }
}

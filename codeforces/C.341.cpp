#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct shark {
    ll l, r, yes, no;
};

shark s[100005];
int n, p;
ll num;
long double tmp;

int main () {
    scanf ("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        ll q = 0;
        cin >> s[i].l >> s[i].r;
        for (ll num = s[i].l; num < s[i].r; num++) {
            if (num % p == 0) {
                q = 1+(s[i].r-num)/p;
                break;
            }
        }
        s[i].yes = q;
        s[i].no = s[i].r-s[i].l+1-q;
    }   
    ll q1, q2;
    for (int i = 0; i < n-1; i++) {
        q1 = s[i].l-s[i].r+1;
        q2 = s[i+1].l-s[i+1].r+1;
        tmp += 2000*(s[i].yes*q2 + s[i+1].yes*q1)/(q1+q2);
    }
    q1 = s[n-1].l-s[n-1].r+1;
    q2 = s[0].l-s[0].r+1;
    tmp += 2000*(s[0].yes*q1 + s[n-1].yes*q2)/(q1+q2)/2;
    printf ("%Le\n", tmp); 
}

#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, p;
char s[MAX];

int main () {
    scanf(" %d %d %s", &n, &p, s);
    n--, p--;
    int l, r, st, end;
    l = r = p;
    if (p <= n/2) 
        st = 0, end = n/2;
    else 
        st = n/2 + 1, end = n;
    int ans = 0;
    for (int i = st; i <= end; i++) {
        if (s[i] != s[n - i]) {
            int a, b;
            a = s[i] - 'a', b = s[n - i] - 'a';
            if (a < b) 
                ans += min(b - a, a + (26 - b));
            else    
                ans += min(a - b, b + (26 - a));
            l = min(l, i);
            r = max(r, i);
        }    
    }
    if (p - l < r - p) 
        ans += (2 * (p - l) + r - p);
    else 
        ans += (2 * (r - p) + p - l);
    printf("%d\n", ans);
}


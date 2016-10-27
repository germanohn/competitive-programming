#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int me[4005];

int n, a, b, c;

int dp(int left) {
    if (left == 0) return 0;
    if (left < a && left < b && left < c) return -inf;

    if (me[left] != -1) return me[left];

    int ans = -inf;
    if (left >= a) 
        ans = max(ans, 1 + dp(left - a));
    if (left >= b) 
        ans = max(ans, 1 + dp(left - b));
    if (left >= c) 
        ans = max(ans, 1 + dp(left - c));

    return me[left] = ans;
}

int main() {
    scanf(" %d %d %d %d", &n, &a, &b, &c);
    memset(me, -1, sizeof me);

    printf("%d\n", dp(n));
}

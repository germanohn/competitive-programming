#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int me[100005];

int dp(int val) {
    if (val == 0) return 0;
    if (me[val] != -1) return me[val];

    int ans = inf;
    for (int i = 1; i*i*i <= val; i++) 
        ans = min(ans, 1 + dp(val - i*i*i));

    return me[val] = ans;
}

int main() {
    int n, cont = 1;
    memset(me, -1, sizeof me);
    while(scanf("%d", &n) != EOF) {
        printf("Case #%d: %d\n", cont++, dp(n));
    }
}

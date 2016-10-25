#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    int n, k, ans;
    scanf(" %d %d", &n, &k);
    ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        if (b > k) 
            ans = max(ans, a - (b - k));
        else 
            ans = max(ans, a);
    }
    printf("%d\n", ans);
}


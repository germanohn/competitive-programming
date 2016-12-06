#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, in = 0, ans = 0;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        in -= a, in += b;
        ans = max(ans, in);
    }
    printf("%d\n", ans);
}


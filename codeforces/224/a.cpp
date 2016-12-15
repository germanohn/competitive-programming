#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int a, b, c, ans = 0;
    scanf(" %d %d %d", &a, &b, &c);
    for (int i = 1; !ans && i <= 10000; i++) {
        if (a % i == 0 && b % i == 0 && ((a/i) * (b/i) == c))
            ans = 4 * (a/i + b/i + i);
    }
    printf("%d\n", ans);
}


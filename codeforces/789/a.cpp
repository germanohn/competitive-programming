#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, k;
int v[N];

int main () {
    scanf(" %d %d", &n, &k);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        ans += ll((a + k - 1) / k);
    }

    printf("%lld\n", (ans + 1) / 2);
}


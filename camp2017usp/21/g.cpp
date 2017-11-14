#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, k;
int a[N];

int main () {
    scanf(" %d %d", &n, &k);
    int _min = N;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
        _min = min(_min, a[i]);

        if (i < k)
            sum += a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n - k + 1; i++) {
        int j = i + k - 1;
        while (sum >= 0) {
            while (a[j] == _min) j--;
            int change = min(sum + 1, a[j] - _min);
            a[j] -= change;
            sum -= change;
            ans += ll(change);
        }

        sum -= a[i];
        if (i + k < n) sum += a[i + k];
    }

    printf("%lld\n", ans);
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]);
    printf("\n");
}


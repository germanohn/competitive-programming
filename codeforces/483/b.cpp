#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll N = 1e11;

int cnt1, cnt2, x, y;

int main () {
    scanf(" %d %d %d %d", &cnt1, &cnt2, &x, &y);

    ll lo = 1;
    ll hi = N;
    while (lo != hi) {
        ll mid = (lo + hi) / 2;
        ll f[] = {mid - mid / x, mid - mid / y, mid - mid / (x * y)};
        if (f[0] >= cnt1 && f[1] >= cnt2 && f[2] >= cnt1 + cnt2)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%lld\n", lo);
}


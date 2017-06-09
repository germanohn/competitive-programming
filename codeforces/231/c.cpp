#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, k;
ll v[N], acc[N];

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf(" %lld", &v[i]);
    sort(v, v + n);
    for (int i = 0; i < n; i++) 
        acc[i + 1] = v[i] + acc[i];

    int _max = 0, num;
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = i - 1; 
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ll(i - mid) * v[i] - (acc[i] - acc[mid]) <= k)
                hi = mid;
            else 
                lo = mid + 1;
        }
        if (i - lo + 1 > _max) 
            _max = i - lo + 1, num = v[i];
    }

    printf("%d %d\n", _max, num);
}


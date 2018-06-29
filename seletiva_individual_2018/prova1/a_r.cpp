#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int main() {
    int n, t, _case = 1;
    while (scanf(" %d %d", &n, &t) && (n != 0 || t != 0)) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            scanf(" %d", &x);
            v.pb(x);
        }
        sort(v.begin(), v.end());
        int a = 0;
        int b = n * n;
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1;
            if (v[i] * v[0] <= t) {
                int lo = 0, hi = n - 1;
                while (lo != hi) {
                    int mid = (lo + hi) / 2;
                    if (v[i] * v[mid] <= t) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    } 
                }
                l = lo;
            }
            if (v[i] * v[n - 1] <= t) {
                int lo = 0, hi = n - 1;
                while (lo != hi) {
                    int mid = (lo + hi + 1) / 2;
                    if (v[i] * v[mid] <= t) {
                        hi = mid - 1;
                    } else {
                        lo = mid;
                    } 
                }
                r = lo; 
            }
            //printf("l %d r %d\n", l, r);
            if (l <= r)
                a += r - l + 1;
        }

        int d = gcd(a, b);
        printf("Case %d: %d/%d\n", _case++, a / d, b / d);
    }
}

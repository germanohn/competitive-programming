#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n, x;
        scanf(" %d %d", &n, &x);
        for (int i = 0; i < n; i++) {
            scanf(" %d", &v[i]);
        }
        int lo = 1, hi = n;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) 
                hi = mid;
            else 
                lo = mid + 1;
        }
    }
}


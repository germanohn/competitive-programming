#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int n;
vector<int> b, c;

bool possible(int x) {
    /*
    for (int i = 0; i < n; i++) {
        printf("b[i] %d c[i] %d\n", b[i], c[i]);
    }
    */
    int l, r;
    for (l = 0, r = n - x; l < x; l++, r++) {
        if (b[l] > c[r])
            return false;
    }

    for (r = 0; l < n; l++, r++) {
        if (b[l] < c[r]) 
            return false;
    }

    return true;
}

int min_inside(int x) {
    int lo = 1, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        // printf("mid %d\n", mid);
        if (possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
        //printf("lo %d hi %d\n", lo, hi);
    }

int max_inside(int x) {
    int lo = 1, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        // printf("mid %d\n", mid);
        if (possible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
        //printf("lo %d hi %d\n", lo, hi);
    }
    return lo;
}

int main() {
    int t, ans;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            int bi;
            scanf(" %d", &bi);
            b.pb(bi);
        }

        sort(b.begin(), b.end());

        int num = 1;
        for (int i = 0; i < n; i++) {
            while (num < b[i]) {
                c.pb(num);
                num++;
            }
            num++;
        }
        while (num <= 2 * n) {
            c.pb(num);
            num++;
        }
        /*
        for (int i = 0; i < n; i++) {
            printf("b[i] %d c[i] %d\n", b[i], c[i]);
        }
        */

        int inside = (lo == hi && possible(lo)) ? lo : 0;
        int mini = possible(0);
        int maxi = possible(n); 
        printf("mini x %d inside %d maxi x %d\n", mini, inside, maxi);
        ans = inside + possible(0) + possible(n);
        printf("%d\n", ans);
        ans = 0;
        b.clear(), c.clear();
    }
}


#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int t, n, w, l;
int wag[N];

int next_wagon(int cur_wag, int len) {
    return min(cur_wag + len, n + 1);
}

bool ok(int len) {
    int cur_wag = 1;
    int idx_wag = 0, k = 0;
    bool has = false;
    while (cur_wag <= n) {
        while (idx_wag < w && wag[idx_wag] < cur_wag)
            idx_wag++;
        if (idx_wag < w && wag[idx_wag] == cur_wag) 
            has = true;
        
        if (has) {
            cur_wag = next_wagon(cur_wag, len);
            has = false;
        } else if (idx_wag >= w) {
            cur_wag = n + 1;
        } else {
            if (wag[idx_wag] - cur_wag <= len - 1) {
                cur_wag = next_wagon(cur_wag, len);
            } else {
                cur_wag = wag[idx_wag];
            }
        }
        k++;
    }

    return k <= l;
}

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d %d", &n, &w, &l);
        for (int i = 0; i < w; i++) 
            scanf(" %d", &wag[i]);

        int lo = 1, hi = n;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) 
                hi = mid;
            else 
                lo = mid + 1;
        }

        printf("%d\n", lo);
    }
}


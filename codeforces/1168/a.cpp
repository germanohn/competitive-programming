#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;

int n, m;
int a[N];

bool is_enough(int k) {
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < last) {
            if (last - a[i] > k) 
                return false;
        } else if (a[i] > last) {
            if (m - a[i] + last > k) 
                last = a[i];
        }
    }
    return true;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    int lo = 0, hi = m - 1;
    while (lo != hi) {
        int mid = (lo + hi) / 2;
        if (is_enough(mid)) 
            hi = mid;
        else 
            lo = mid + 1;
    }

    printf("%d\n", lo);
}


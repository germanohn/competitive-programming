#include<bits/stdc++.h>
using namespace std;

const int MAX = 200005;

int n, m;
int a[MAX], b[MAX];

/*
int bb(int val) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (a[mid] > val)
            r = mid;
        else 
            l = mid + 1;
    }

    return l;
}*/

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf(" %d", &b[i]);
    }

    sort(a, a + n);

    int at = 0;
    for (int i = 0; i < m; i++) {
        int ans = upper_bound(a, a + n, b[i]) - a;
        //int ans = bb(b[i]);
        printf("%d ", ans);
    }
    printf("\n");
}

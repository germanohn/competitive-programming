#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, q, a;
int v[N];

int bb(int lo, int hi) {
    if (lo == hi) 
        return lo;
    int mid = (lo + hi) / 2;
    printf("mid %d\n", mid);
    if (v[mid] > a)
        return bb(lo, mid - 1);
    else if (v[mid] == a)
        return bb(lo, mid);
    else
        return bb(mid + 1, hi);
}

int main () {
    scanf(" %d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    while (q--) {
        scanf(" %d", &a);
        int lo = bb(0, n - 1);
        //int lo = 0, hi = n - 1;
        /*while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (v[mid] > a)
                hi = mid - 1;
            else if (v[mid] == a)
                hi = mid;
            else 
                lo = mid + 1;
        }*/
        if (v[lo] == a) printf("%d\n", lo);
        else printf("-1\n");
    }
}


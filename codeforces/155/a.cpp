#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    int v[1005];
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);

    int lo, hi, ans;
    lo = hi = v[0], ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < lo || v[i] > hi) ans++;
        if (v[i] < lo) lo = v[i];
        if (v[i] > hi) hi = v[i];
    }

    printf("%d\n", ans);
}


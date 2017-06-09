#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n, k;
int best[N];
ll acc[N];

ll sum(int l) {
    return acc[l + k - 1] - acc[l - 1];
}

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %lld", &acc[i + 1]);
        acc[i + 1] += acc[i];
    }

    best[n - k + 1] = n - k + 1;
    for (int i = n - k; i >= k + 1; i--) {
        ll cur = sum(i), nx = sum(best[i + 1]);
        if (nx > cur) 
            best[i] = best[i + 1];
        else 
            best[i] = i;
    }

    int l = 1;
    for (int i = 2; i <= n - (2 * k) + 1; i++) {
        ll aux = sum(i) + sum(best[i + k]);
        if (aux > sum(l) + sum(best[l + k]))
            l = i;
    }
    printf("%d %d\n", l, best[l + k]);
}


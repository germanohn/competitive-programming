#include <bits/stdc++.h>
#define MAX 10000100

using namespace std;

int t, n, bit[MAX], ind;
long long int ans, maior;

void update (int idx, int val) {
    for (int i = idx; i < MAX; i += i & -i)
        bit[i] += val;
}

long long int query (int idx) {
    long long int sum = 0;
    for (int i = idx; i > 0; i -= i & -i) 
        sum += bit[i];
    return sum;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 0; i < MAX; i++)
            bit[i] = 0;
        ans = 0, maior = 0;
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &ind);
            ans += query (MAX - 5) - query (ind);
            update (ind, 1);
        }
        printf ("%lld\n", ans); 
    }
}


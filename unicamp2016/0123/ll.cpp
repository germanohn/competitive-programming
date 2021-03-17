// count inversions with bit
#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;
typedef long long ll;

map<ll, int> m;

void update (int val) {
    for (int i = val; i < MAX; i += i&-i)
        bit[i] += 1;
}

int query (int val) {
    int sum = 0;
    for (int i = val; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main () {
    int n, k;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        query (a);
        update (a);
    }
}

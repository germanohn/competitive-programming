#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int n;
int new_value[N], aux[N];
ll bit[N];
int p[3][N];

void update(int idx, ll val) {
    for (int i = idx; i < N; i += i & -i)
        bit[i] += val;
}

ll query(int idx) {
    ll ret = 0;
    for (int i = idx; i > 0; i -= i & -i)
        ret += bit[i];
    return ret;
}

ll count_inversions(int a, int b) {
    for (int i = 0; i < n; i++) {
        new_value[p[a][i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        aux[i] = new_value[p[b][i]];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += i - query(aux[i]);
        update(aux[i], 1);
    }
    return ans;
}

void clean() {
    for (int i = 0; i < N; i++) 
        bit[i] = 0;
}

int main() {
    while (scanf(" %d", &n) != EOF) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %d", &p[i][j]);
            }
        }

        ll inversions = 0;
        inversions += count_inversions(0, 1);
        clean();
        inversions += count_inversions(1, 2);
        clean();
        inversions += count_inversions(0, 2);
        clean();
        printf("%lld\n", (ll(n) * ll(n - 1) - inversions) / 2);
    }
}


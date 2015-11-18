#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100000;
const int MAX = 200005;

int n, m, pai[MAX], w[MAX];
ll sum[MAX];

int find (ll a) {
    if (a == pai[a]) return a;
    return pai[a] = find (pai[a]);
}

void join (ll a, ll b) {
    a = find (a), b = find (b);
    if (a != b) {
        if (w[a] < w[b]) swap (a, b);
        pai[b] = a;
        w[a] += w[b];
        sum[a] += sum[b];
    }
}

int main () {
    ll p, q, a;
    while (scanf ("%d %d", &n, &m) != EOF) {
        for (ll i = 1; i <= n; i++) {
            pai[i] = i+N;
            pai[i+N] = i+N;
            w[i+N] = 1;
            sum[i+N] = i;
        }
        for (int i = 0; i < m; i++) {
            scanf ("%lld", &a);
            if (a == 1) {
                scanf ("%lld %lld", &p, &q);
                join (p, q);
            }
            else if (a == 2) {
                scanf ("%lld %lld", &p, &q);
                w[find (p)]--;
                sum[find (p)] -= p;
                pai[p] = find (q);
                w[find (q)]++;
                sum[find (q)] += p;
            }
            else {
                scanf ("%lld", &p);
                p = find (p);
                printf ("%d %lld\n", w[p], sum[p]);

            }
        }
    }
}

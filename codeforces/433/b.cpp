#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m;
ll cost[MAX], v[MAX], u[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &cost[i]);
        v[i + 1] = v[i] + cost[i];
    }
    sort(cost, cost + n);
    for (int i = 0; i < n; i++) 
        u[i + 1] = u[i] + cost[i];
    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        int type, l, r;
        scanf(" %d %d %d", &type, &l, &r);
        if (type == 1) {
            printf("%lld\n", v[r] - v[l - 1]);
        } else {
            printf("%lld\n", u[r] - u[l - 1]);
        }
    }
}


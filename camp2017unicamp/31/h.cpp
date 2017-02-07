#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 500005;

int n, m, k;
int bit[MAX];

void update(int idx, int val) {
    for (int i = idx; i < MAX; i += i & -i)
        bit[i] += val;
}

int query(int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) 
        ans += bit[i];
    return ans;
}

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) 
        update(i, 1);
    int dead = 0, l = 1, h = n;
    while (true) {
        int alive_n, alive_i, aux_m;
        alive_n = query(n);
        alive_i = query(l - 1);
        aux_m = m;
        if (aux_m > alive_n - alive_i) {
            aux_m -= (alive_n - alive_i);
            if (aux_m % (n - dead) == 0) aux_m = n - dead;
            else aux_m = (aux_m % (n - dead));
            l = 1, h = n;
        }
        int lf = l;
        while (l != h) {
            int mid = (l + h) / 2;
            if (query(mid) - query(lf - 1) >= aux_m)
                h = mid;
            else 
                l = mid + 1;
        }
        update(l, -1), dead++;
        if (l == k) 
            break;
        if (!(query(n) - query(l))) l = 1;
        else {
            if (l == n) l = 1;
            else l++;
        }
        h = n;
    }
    printf("%d\n", dead);
}


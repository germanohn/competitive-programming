#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5e4 + 5;
const int MAX = 5e5 + 5;

int n, m;
int a[N], clos[N], p[MAX], t[4 * N];
vector<int> primes;
vector<int> q[MAX];

void build(int no, int l, int r) {
    if (l == r) {
        t[no] = clos[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * no, l, mid);
    build(2 * no + 1, mid + 1, r);

    t[no] = max(t[2 * no], t[2 * no + 1]);
}

int query(int no, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return -1;
    if (l >= ql && r <= qr) return t[no];

    int mid = (l + r) / 2;
    return max(query(2 * no, l, mid, ql, qr), query(2 * no + 1, mid + 1, r, ql, qr));
}

void sieve() {
    for (int i = 2; i < MAX; i++) {
        if (!p[i]) {
            for (int j = i; j < MAX; j += i) {
                p[j] = i;
            } 
        }
    }
}

int sum_coprimes(int i) {
    int q_cop = 0;
    for (int k = 1; k < (1 << primes.size()); k++) {
        int d = 1;
        int cont = 0;
        for (int j = 0; j < primes.size(); j++) {
            if (((1 << j) & k) != 0) 
                d *= primes[j], cont++;
        }

        int not_cop = upper_bound(q[d].begin(), q[d].end(), i) - q[d].begin();
        if (__builtin_popcount(k) % 2 != 0) {
            q_cop += ((i + 1) - not_cop);
        } else {
            q_cop -= ((i + 1) - not_cop);
        }
    }

    return q_cop;
}

int main() {
    sieve();
    scanf(" %d %d", &n, &m);

    for (int i = 0; i < n; i++) 
        scanf(" %d", &a[i]);

    for (int i = 0; i < n; i++) {
        primes.clear();

        int cur_ai = a[i];
        while (cur_ai > 1) {
            int cur_div = p[cur_ai];
            cur_ai /= p[cur_ai];

            bool found = false;
            for (int j = 0; j < primes.size(); j++) {
                if (cur_div == primes[j]) 
                    found = true;
            } 

            if (!found) primes.pb(cur_div);
        }

        // calcula quantidade de coprimos a x antes de i: q_cop
        int q_cop = sum_coprimes(i - 1);

        int lo = 0, hi = i - 1; 
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (sum_coprimes(mid) == q_cop) 
                hi = mid;
            else 
                lo = mid + 1;
        }

        if (lo > hi || sum_coprimes(lo) < q_cop || sum_coprimes(lo) == 0) clos[i] = -1;
        else clos[i] = lo;

        for (int k = 1; k < (1 << primes.size()); k++) {
            int d = 1;
            for (int j = 0; j < primes.size(); j++) {
                if (((1 << j) & k) != 0) 
                    d *= primes[j];
            }

            q[d].pb(i);
        }
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        l--, r--;
        if (query(1, 0, n - 1, l, r) >= l) printf("S\n");
        else printf("N\n");
    }
}


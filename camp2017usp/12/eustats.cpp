#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 250005;

int n;
pii pr[N];
vector<int> t[4 * N];

void merge(int no, int l, int r) {
    int i = 0, j = 0;
    while (i < t[l].size() && j < t[r].size()) {
        if (t[l][i] <= t[r][j]) {
            t[no].pb(t[l][i]);
            i++;
        } else {
            t[no].pb(t[r][j]);
            j++;
        }
    }

    while (i < t[l].size()) 
        t[no].pb(t[l][i++]);

    while (j < t[r].size()) 
        t[no].pb(t[r][j++]);
}

void build(int no, int l, int r) {
    if (l == r) {
        t[no].pb(pr[l].ss);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * no, l, mid);
    build(2 * no + 1, mid + 1, r);

    merge(no, 2 * no, 2 * no + 1);
}

int query(int no, int l, int r, int ql, int qr, int cj, int dj) {
    if (ql > r || qr < l) return 0;
    if (l >= ql && r <= qr) {
        int lo = lower_bound(t[no].begin(), t[no].end(), cj) - t[no].begin();
        int hi = upper_bound(t[no].begin(), t[no].end(), dj) - t[no].begin() - 1;
        return hi - lo + 1;
    }

    int mid = (l + r) / 2;
    return query(2 * no, l, mid, ql, qr, cj, dj) +
           query(2 * no + 1, mid + 1, r, ql, qr, cj, dj);
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &pr[i].ff, &pr[i].ss);
    }

    sort(pr, pr + n);

    build(1, 0, n - 1);

    int last[4] = {0, 0, 0, 0};    

    int q;
    scanf(" %d", &q);
    for (int i = 0; i < q; i++) {
        int ej, fj, gj, hj;
        scanf(" %d %d %d %d", &ej, &fj, &gj, &hj);

        int aj, bj, cj, dj;
        aj = ej ^ last[3];
        bj = fj ^ last[2];
        cj = gj ^ last[1];
        dj = hj ^ last[0];
        if (aj > bj) swap(aj, bj);
        if (cj > dj) swap(cj, dj);

        for (int i = 3; i > 0; i--)
            last[i] = last[i - 1];

        aj = lower_bound(pr, pr + n, pii(aj, 0)) - pr;
        bj = upper_bound(pr, pr + n, pii(bj + 1, -1)) - pr - 1;

        last[0] = query(1, 0, n - 1, aj, bj, cj, dj);
        printf("%d\n", last[0]);
    }
}












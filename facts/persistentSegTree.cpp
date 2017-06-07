/* Problem : Given an array A[] and different point update operations.Considering 
 * each point operation to create a new version of the array. We need to answer 
 * the queries of type
 * Q v l r : output the sum of elements in range l to r just after the v-th update. */

#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;

int nodes;
int a[N];
int t[4 * N];
int lc[4 * N], rc[4 * N];
int root[N];

void build(int no, int l, int r) {
    if (l == r) { 
        t[no] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    lc[no] = nodes++;
    rc[no] = nodes++;
    build(lc[no], l, mid);
    build(rc[no], mid + 1, r);
    t[no] = t[lc[no]] + t[rc[no]];
}

void update(int ant, int cur, int l, int r, int ind, int val) {
    if (l == r) {
        t[cur] = val;
        return;
    }

    printf("ant %d cur %d l %d r %d ind %d val %d\n", ant, cur, l, r, ind, val);
    int mid = (l + r) / 2;
    if (ind <= mid) {
        rc[cur] = rc[ant];
        lc[cur] = nodes++;
        update(lc[ant], lc[cur], l, mid, ind, val);    
    } else {
        lc[cur] = lc[ant];
        rc[cur] = nodes++;
        update(rc[ant], rc[cur], mid + 1, r, ind, val);
    }
    t[cur] = t[lc[cur]] + t[rc[cur]];
} 

int query(int no, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[no];
    if (r < ql || l > qr) return 0;
   
    int mid = (l + r) / 2;
    return query(lc[no], l, mid, ql, qr) + query(rc[no], mid + 1, r, ql, qr);
}

int main () {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }
    nodes++;
    build(0, 0, n - 1);

    int p;
    scanf(" %d", &p);
    for (int i = 1; i <= p; i++) {
        int ind, val;
        scanf(" %d %d", &ind, &val);
        root[i] = nodes++;
        update(root[i - 1], root[i], 0, n - 1, ind, val);
    }

    int q;
    scanf(" %d", &q);
    while (q--) {
        int a, b, v;
        scanf(" %d %d %d", &v, &a, &b);
        printf("%d\n", query(root[v], 0, n - 1, a, b));
    }
}








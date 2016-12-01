#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

struct node {
    int key, l, r;
}

int t, n, m;
node tree[MAX];

void insert(int no, int val) {
    if (tree[no].key = -1) tree[no].key = val;
    if (val < tree[no].key) {
        if (tree[no].l == -1) insert(2 * no, val);
        else tree[no].l = val;
    } else {
        if (tree[no].r == -1) insert(2 * no + 1, val);
        else tree[no].r = val;
    }
}



int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            int a;
            scanf(" %d", &a);
            insert(1, a);
        }

        solve();
    }
}


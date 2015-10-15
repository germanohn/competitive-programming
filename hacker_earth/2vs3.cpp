#include <bits/stdc++.h>

using namespace std;

int n, q, type, l, r, tree[400005], A[100005], ans;   
char c[100005];

int build (int node, int start, int end) {
    if (start == end) 
        tree[node] = A[start];
    else {
        int mid = (start+end)/2;
        build (2*node,start,mid);
        build (2*node+1,mid+1,end);
        tree[node]=(tree[2*node]+tree[2*node+1])%3;
    }
}

void update (int node, int start, int, 

int query (int node, int st, int en, int l, int r) {
    if (r < st || en < l)
        return 0;
    if (l <= st && en <= r) {
    }
}

int main () {
    scanf ("%d %s %d", &n, c, &q);
    int k = n-1;
    for (int i=1;i<=n;i++) 
        A[i] = ((c[i-1]-'0')*pow(2,k--))%3;
    build (1, 1, n);
    for (int i = 0; i < q; i++) {
        scanf ("%d", &type);
        if (!type) {
            scanf ("%d %d", &l, &r);
            ans = query (1, 1, n, l+1, r+1);
            printf ("%d\n", ans);
        }
        else {
            scanf ("%d", &f);
            update
        }

    }
}

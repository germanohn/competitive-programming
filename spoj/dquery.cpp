#include <bits/stdc++.h>
#define ff first 
#define ss second 

using namespace std;

typedef pair<int, int> pii;

int n, v[1000005], bit[1000005], vis[1000005], ult[1000005], q, ans[1000005];
map<int, int> m;
pair<int, int> ar[1000005];
pair<pii, int> que[1000005];

bool comp (pair<pii, int> a, pair<pii, int> b) {
    return a.ff.ss < b.ff.ss;
}

bool comp2 (pii a, pii b) {
    return a.ss < b.ss;
}

void update (int idx, int val) {
    for (int i = idx; i <= n; i += i & -i)
        bit[i] += val;
}

int query (int ind) {
    int sum = 0;
    for (int i = ind; i > 0; i -= i & -i) 
       sum += bit[i];
    return sum; 
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) { 
        scanf ("%d", &ar[i].ff);
        ar[i].ss = i;
    }
    sort (ar, ar + n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        int aux = ar[i].ff;
        if (m.find (aux) == m.end ())
            m[aux] = k++;
        ar[i].ff = m[aux];
    }
    sort (ar, ar + n, comp2);
    for (int i = 0; i <= n; i++)
        vis[i] = 0;
    scanf ("%d", &q);
    int quant, x, y;
    for (int i = 0; i < q; i++) {
        scanf ("%d %d", &x, &y);
        que[i].ff.ff = x;
        que[i].ff.ss = y;
        que[i].ss = i;
    }
    sort (que, que + q, comp);
    int s = 1;
    for (int i = 0; i < q; i++) {
        x = que[i].ff.ff;
        y = que[i].ff.ss;
        for (int j = s; j <= y; j++) {
            int num = ar[j-1].ff;
            if (!vis[num]) {
                update (j, 1);
                vis[num]++;
                ult[num] = j;
            }
            else {
                update (ult[num], -1);
                ult[num] = j;
                update (j, 1);
            }
        }
        ans[que[i].ss] = query (y) - query (x-1);
        s = y + 1;
    }
    for (int i = 0; i < q; i++) 
        printf ("%d\n", ans[i]);
}

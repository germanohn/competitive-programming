#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int t, n, acc;
int v[MAX];
pii ans[10000005];

int main () {
    scanf ("%d", &t);
    bool f = false;
    while (t--) {
        if (f) printf ("\n");
        f = true;
        acc = 0;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
        }
        sort (v, v+n);
        int q = n, k = 0;
        while (q) {
            if (q == 1) {
                acc += v[0];
                ans[k++] = pii (v[0], 0);
                q--; 
            } else if (q == 2) {
                acc += v[1];
                ans[k++] = pii (v[0], v[1]);
                q -= 2;
            } else if (q == 3) {
                int l = 0;
                acc += v[l]+v[l+1]+v[l+2]; 
                ans[k++] = pii (v[l], v[l+1]);
                ans[k++] = pii (v[l], 0);
                ans[k++] = pii (v[l], v[l+2]);   
                q -= 3;
            } else {
                int l = 0, h = q-1;
                if (2*v[l]+v[h-1]+v[h] < v[l]+2*v[l+1]+v[h]) {
                    acc += 2*v[l]+v[h-1]+v[h];
                    ans[k++] = pii (v[l], v[h-1]);
                    ans[k++] = pii (v[l], 0);
                    ans[k++] = pii (v[l], v[h]);
                    ans[k++] = pii (v[l], 0);
                } else {
                    acc += v[l]+2*v[l+1]+v[h];
                    ans[k++] = pii (v[l], v[l+1]);
                    ans[k++] = pii (v[l+1], 0);
                    ans[k++] = pii (v[h-1], v[h]);
                    ans[k++] = pii (v[l], 0);
                }
                q -= 2;
            }
        }
        printf ("%d\n", acc);
        for (int i = 0; i < k; i++) {
            if (ans[i].ss == 0)
                printf ("%d\n", ans[i].ff);
            else 
                printf ("%d %d\n", ans[i].ff, ans[i].ss);
        }
    }
}


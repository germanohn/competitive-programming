#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000007;
const int MAX = 50005;
inline ll mod (ll x) { return x % modn; }

int n;
int p[MAX], a[MAX], b[MAX], c[MAX];
int v[MAX], bit[MAX];

void update (int idx, int val) {
    for (int i = idx+2; i < MAX; i += i & -i)
        bit[i] += val;
}

int query (int idx) {
    int sum = 0;
    for (int i = idx+2; i > 0; i -= i & -i) 
       sum += bit[i];
    return sum; 
}

bool compare (int x, int y) {
    return b[x] < b[y];
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        for (int i = 0; i < MAX; i++) 
            bit[i] = 0;
        int ma = INT_MIN;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d %d", &a[i], &b[i], &c[i]);
            p[i] = i;
            ma = max (ma, b[i]);
        }
        sort (p, p + n, compare);
        for (int i = ma+1; i > 0; i--) 
            v[i] = i-1;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int q = query (b[p[i]]) - query (a[p[i]]-1);
            while (q < c[p[i]]) {
                int point = b[p[i]] + 1;
                update (v[point], 1);  
                v[point] = v[v[point]], q++, ans++;
            }   
        }
        printf ("%lld\n", ans);
    }
}

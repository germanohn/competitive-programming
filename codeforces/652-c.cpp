#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 3e5 + 5;

int n, m;
int v[MAX], pos[MAX], lf[MAX];

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        pos[v[i]] = i;
        lf[v[i]] = n;
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        if (pos[a] > pos[b]) {
            lf[b] = min (lf[b], pos[a]);
        } else {
            lf[a] = min (lf[a], pos[b]);
        }
    }
    ll ans = 0;
    int firstOk = n-1;
    for (int i = n-1; i >= 0; i--) {
        firstOk = min (firstOk, lf[v[i]]-1);
        ans += (ll) firstOk-i+1;
    }
    cout << ans << "\n";
}

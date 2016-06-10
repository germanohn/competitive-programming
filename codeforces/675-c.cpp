#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 5;

int n;
int v[MAX];
map<ll, int> m;

int main () {
    scanf ("%d", &n);
    ll acc = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        acc += (ll) v[i];
        m[acc]++;
    }
    int ans = INT_MAX;
    acc = 0;
    for (int i = 0; i < n; i++) {
        ans = min (ans, n-m[acc]);
        acc += v[i];
    }
    printf ("%d\n", ans);
}


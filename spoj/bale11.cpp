#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 100005;

int bit[MAX];

void update (int ind, int val) {
    for (int i = ind; i < MAX; i += i&-i) 
        bit[i] += val;
}

int query (int ind) {
    int sum = 0;
    for (int i = ind; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main () {
    int n, a, q;
    ll ans = 0; 
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        q = query (n) - query (a);
        ans += ((n-i-1) - (n-a-q)); 
        update (a, 1);
    }
    printf ("%lld\n", ans);
}


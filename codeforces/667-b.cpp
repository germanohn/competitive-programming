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
const int inf = 1123456789;

int n, v[MAX];
ll ans, sum;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        sum += v[i];
    }
    sort (v, v+n);
    sum -= v[n-1];
    ans = v[n-1] - sum + 1;
    cout << ans << endl;
}


#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, double> pid;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n, m, k;

void dfs (int u, double fee) {
    seen[u] = true;
    for (int 
}

int main() {
    while (scanf (" %d", &n)) {
        if (n == 0) break;

        char s1[20], s2[20];
        int k = 1;

        memset (d, 1, sizeof d);

        scanf (" %d", &coin);
        for (int i = 0; i < n; i++) {
            scanf (" %s", s1);
            if (coin[s1] == 0)
               coin[s1] = k++; 
        }

        double fee;
        for (int i = 0; i < m; i++) {
            scanf (" %s %d %s", s1, &fee, s2);
            adj[coin[s1]].pb (pid (coin[s2], fee));
        }

        floyd ();
    }
}


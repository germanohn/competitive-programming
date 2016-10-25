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

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n, q;
char s[40][5];

int cont (char c, int tam) {
    if (tam == n) return 1;
    int ans = 0;
    for (int i = 0; i < q; i++) {
        if (s[i][3] == c) {
            ans += cont (s[i][0], tam+1);
        }
    }
    return ans;
}

int main() {
    scanf (" %d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf (" %[^\n]", s[i]);
    }

    int ans = cont ('a', 1);
    printf ("%d\n", ans);
}


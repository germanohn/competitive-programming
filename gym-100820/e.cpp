#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n;
int v[100005];

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    sort (v, v+n);
    int mini = INT_MAX;
    for (int i = 0; i < n/2; i++) {
        int a = v[i]+v[n-i-1];
        mini = min (mini, a);
    }
    printf ("%d\n", mini);
}


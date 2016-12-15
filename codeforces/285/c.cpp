#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 300005;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + n);
    int nx = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != nx) 
            ans += ll (abs(nx - v[i]));
        nx++;
    }
    printf("%lld\n", ans);
}


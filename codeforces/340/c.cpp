#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
ll v[MAX], acc[MAX];

int gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %lld", &v[i + 1]);
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++) 
        acc[i] = v[i] + acc[i - 1];
    ll num, den, div;
    num = acc[n], den = n;
    for (int i = 1; i <= n; i++) {
        num += (((i - 1) * v[i] - acc[i - 1]) + ((acc[n] - acc[i]) - (n - i) * v[i]));
    }
    div = gcd(num, den);
    num /= div, den /= div;
    printf("%lld %lld\n", num, den);
}


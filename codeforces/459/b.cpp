#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

ll n;
int v[MAX];

int main() {
    scanf(" %lld", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + n);
    ll a, b;
    a = b = 1;
    for (int i = 0; i < n; i++) {
        if (i != 0 && v[i] == v[0]) a++;
        else if (i != n - 1 && v[i] == v[n - 1]) b++;
    }
    if (a == n) printf("%d %lld\n", v[n - 1] - v[0], (n * (n - 1)) / 2);
    else printf("%d %lld\n", v[n - 1] - v[0], a * b);
}

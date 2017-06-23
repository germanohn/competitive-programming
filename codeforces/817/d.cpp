#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int n;
int l[N], r[N];
ll a[N];
stack<int> s;

int main () {
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %lld", &a[i]);
    }

    // min
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] > a[i]) {
            r[s.top()] = i;
            s.pop();
        }
        if (!s.empty()) l[i] = s.top();
        else l[i] = -1;
        s.push(i);
    }

    while (!s.empty()) {
        r[s.top()] = n;
        s.pop();
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans -= (ll(i - l[i]) * ll(r[i] - i) * a[i]);
    }

    // max
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            r[s.top()] = i;
            s.pop();
        }
        if (!s.empty()) l[i] = s.top();
        else l[i] = -1;
        s.push(i);
    }

    while (!s.empty()) {
        r[s.top()] = n;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        ans += (ll(i - l[i]) * ll(r[i] - i) * a[i]); 
    }

    printf("%lld\n", ans);
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
int l[N], r[N];
ll h[N];
stack<int> s;

int main () {
    while (scanf(" %d", &n)) {
        if (n == 0) break;

        for (int i = 0; i < n; i++) 
            scanf(" %lld", &h[i]);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && h[i] <= h[s.top()]) 
                s.pop();
            if (!s.empty()) l[i] = s.top() + 1;
            else l[i] = 0;
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && h[i] <= h[s.top()])
                s.pop();
            if (!s.empty()) r[i] = s.top() - 1;
            else r[i] = n - 1;
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        ll ans = 0;
        for (int i = 0; i < n; i++) 
            ans = max(ans, ll(r[i] - l[i] + 1) * h[i]);

        printf("%lld\n", ans);
    }
}


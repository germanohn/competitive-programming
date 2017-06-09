#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
int h[MAX];

int main () {
    scanf(" %d", &n);
    ll energy = 0, ans = 0;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf(" %d", &cur);
        if (cur > pre + energy) {
            ans += (cur - (pre + energy));
            energy = 0;
        } else {
            energy += (pre - cur);
        }
        pre = cur;
    }
    printf("%lld\n", ans);
}

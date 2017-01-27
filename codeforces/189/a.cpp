#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/* solucao com dp
const int inf = 1e9;

int n;
int v[5], me[4005];

int dp(int x) {
    if (x == 0) return 0;
    if (x < v[0] || x < 0) return -inf;
    if (me[x] != -1) return me[x];
    return me[x] = max(1 + dp(x - v[0]), max(1 + dp(x - v[1]), 1 + dp(x - v[2])));
}

int main () {
    scanf(" %d", &n);
    memset(me, -1, sizeof me);
    for (int i = 0; i < 3; i++)
        scanf(" %d", &v[i]);
    sort(v, v + 3);
    printf("%d\n", dp(n));
}
*/

int n;
int v[5];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < 3; i++) 
        scanf(" %d", &v[i]);
    sort(v, v + 3);
    int ans = 0;
    for (int x = 0; x * v[0] <= n; x++) {
        for (int y = 0; y * v[1] <= n - (x * v[0]); y++) {
            int left = n - (x * v[0] + y * v[1]);
            if (left % v[2] == 0) 
                ans = max(ans, x + y + (left / v[2]));
        }
    }
    printf("%d\n", ans);
}

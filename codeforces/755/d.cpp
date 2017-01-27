#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int n, k;
ll bit[MAX];

void update(int idx, ll val) {
    for (int i = idx; i < MAX; i += i & -i) 
        bit[i] += val;
}

ll query(int idx) {
    ll ans = 0;
    for (int i = idx; i > 0; i -= i & -i)
       ans += bit[i];
    return ans; 
}

int main() {
    scanf(" %d %d", &n, &k);
    int now = 1 + k;
    ll ans = 2;
    printf("%lld ", ans);
    update(1, 1);
    for (int i = 1; i < n; i++) {
        //printf("now %d\n", now);
        if (now - k < 1) {
          //  printf("(%d, ", now - k + n + 1);
            ans += (query(now) + (query(n) - query(now - k + n)));
        } else {
            //printf("(%d, ", now - k + 1);
            ans += (query(now) - query(now - k));
        }
        if (now + k > n) { 
            //printf("%d)\n", now + k - n - 1);
            ans += (query(now + k - n - 1) + (query(n) - query(now)));
        } else { 
            //printf("%d)\n", now + k - 1);
            ans += (query(now + k - 1) - query(now));
        }
        update(now, 1);
        if (now + k > n) now = now + k - n;
        else now = now + k;
        ans++;
        printf("%lld ", ans);
    }
    printf("\n");
}

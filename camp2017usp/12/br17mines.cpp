#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int t, n;
int l[N], r[N];
ll m[N][2];

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %lld %lld", &m[i][0], &m[i][1]);
        }

        l[0] = 0;
        for (int i = 1; i < n; i++) {
            if (m[i][0] - m[i][1] <= m[i - 1][0])
                l[i] = l[i - 1];
            else
                l[i] = i;
        }

        r[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (m[i][0] + m[i][1] >= m[i + 1][0])
                r[i] = r[i + 1];
            else 
                r[i] = i;
        }

        for (int i = 0; i < n - 1; i++) {
            printf("%d ", r[i] - l[i] + 1);
        }
        printf("%d\n", r[n - 1] - l[n - 1] + 1);
    }
}


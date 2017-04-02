#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2e5 + 5;

int n, m;
bool seen[MAX];

int main () {
    scanf(" %d %d", &n, &m);

    while (m--) {
        int k;
        scanf(" %d", &k);
        memset(seen, 0, sizeof seen);
        bool cancel = true;
        for (int i = 0; i < k; i++) {
            int a;
            scanf(" %d", &a);
            if (a < 0) {
                a = abs(a);
                seen[(2 * a) ^ 1] = true;
            } else 
                seen[2 * a] = true;

            if (seen[2 * a] && seen[(2 * a) ^ 1]) 
                cancel = false;
        }

        if (cancel) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
}


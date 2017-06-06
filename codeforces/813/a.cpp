#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;

int main () {
    int n, m;
    scanf(" %d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        sum += a;
    }

    scanf(" %d", &m);

    for (int i = 0; i < m; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        if (r >= sum) {
            if (sum >= l) {
                printf("%d\n", sum);
            } else {
                printf("%d\n", l);
            }
            return 0;
        }
    }

    printf("-1\n");
}


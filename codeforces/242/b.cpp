#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int v[100005][2];

int main () {
    int n, l = INT_MAX, r = -1;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &v[i][0], &v[i][1]);
        l = min(l, v[i][0]);
        r = max(r, v[i][1]);
    }
    for (int i = 0; i < n; i++) {
        if (v[i][0] == l && v[i][1] == r) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
}


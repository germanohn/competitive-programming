#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 5;

int n, m;
int freq[N], color[N];

int main () {
    scanf(" %d %d", &n, &m);
    int c = 0;
    for (int i = 0; i < n; i++) {
        int sz;
        scanf(" %d", &sz);
        int cur = 1;
        for (int j = 0; j < sz; j++) {
            int t;
            scanf(" %d", &t);
            if (freq[t] < sz) {
                freq[t] = sz;
                color[t] = cur++;
            }
        }
        cur--;
        c = max(c, cur);
    }
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        scanf(" %d %d", &a, &b);
    }

    printf("%d\n", c);
    for (int i = 1; i <= m; i++) 
        printf("%d ", color[i]);
    printf("\n");
}


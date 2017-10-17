#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int p[N], sz[N];

int find(int a) {
    if (p[a] == a) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = p[a];
    sz[a] += sz[b];
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        p[i] = 0, sz[i] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k;
        scanf(" %d", &k);
        if (!k) { 
            ans++;
        } else {
            int pre, cur;
            scanf(" %d", &pre);
            if (!p[pre]) p[pre] = pre;
            while (k > 1) {
                scanf(" %d", &cur);
                if (!p[cur]) p[cur] = cur;
                join(pre, cur);
                pre = cur;
                k--;
            }
        }
    }

    int comp = 0;
    for (int i = 1; i <= m; i++) {
        if (p[i] == i)
            comp++;
    }

    ans += max(0, comp - 1);
    printf("%d\n", ans);
}


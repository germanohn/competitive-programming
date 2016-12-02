#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 200005;

int pai[MAX], sz[MAX];
int color[MAX], permut[MAX];
map<int, int> freq;

int find(int a) {
    if (a == pai[a]) return a;
    return pai[a] = find(pai[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    pai[a] = pai[b];
    sz[b] += sz[a];
}

bool cmp(int a, int b) {
    return find(a) < find(b);
}

int main() {
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf(" %d", &color[i]);
        permut[i] = i;
        pai[i] = i;
        sz[i] = 1;
    }
    pai[n] = n, sz[n] = 1, permut[n] = n;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        join(a, b);
    }

    sort(permut, permut + n + 1, cmp);

    int ans = 0, aux = 0, cur = find(permut[0]);
    for (int i = 0; i <= n; i++) {
        if (find(permut[i]) != cur && aux != 0) {
            freq.clear();
            ans += sz[cur] - aux;
            aux = 0;
            cur = find(permut[i]);
        } else {
            freq[color[permut[i]]]++;
            aux = max(aux, freq[color[permut[i]]]);
        }
    }

    printf("%d\n", ans);

}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100005;

int n, m;
int bit[MAX], v[MAX], a[MAX];
int seen[MAX];

void update (int idx, int val) {
    for (int i = idx; i <= n; i += i&-i)
        bit[i] += val;
}

int query (int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main () {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) 
        bit[i] = 0;

    for (int i = 0; i < MAX; i++)
        seen[i] = -1;
    
    for (int i = 0; i < n; i++) 
        scanf("%d", &v[i]);

    int acc_prep = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
        acc_prep += a[i];
    }

    int qtd_seen = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            if (seen[v[i]] == -1) {
                update(i + 1, a[v[i]]);
                seen[v[i]] = i;
                qtd_seen++;
            } else {
                update(seen[v[i]] + 1, -1);
                seen[v[i]] = i;
            }
        } else {
            update(i + 1, -1);
        }

        if (qtd_seen == m && i + 1 - acc_prep >= m) {
            int tot;
            tot = query(i + 1);
            if (tot <= 0) {
                printf("%d\n", i + 1);
                return 0;
            }
        }
    }
    printf("-1\n");
}


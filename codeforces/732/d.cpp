#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100005;

int n, m, l, r;
int d[MAX], a[MAX], seen[MAX];

bool can_pass(int last_day) {
    int acc_prep, cont;
    acc_prep = cont = 0;

    for (int i = 0; i <= m; i++) 
        seen[i] = -1;

    for (int i = last_day; i >= 0; i--)
        if (d[i] != 0 && seen[d[i]] == 0) seen[d[i]] = i, cont++;

    if (cont < m) return false;

    for (int i = 0; i <= last_day; i++) {
        if (d[i] != 0 && seen[d[i]] == i) 
            acc_prep -= a[d[i]];
        else 
            acc_prep++;
        if (acc_prep < 0) return false;
    }

    return true;
}

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &d[i]);

    for (int i = 1; i <= m; i++) 
        scanf(" %d", &a[i]);

    l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (can_pass(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    if (can_pass(l)) printf("%d\n", l + 1);
    else printf("-1\n");
}


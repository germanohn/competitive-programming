#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

pii v[MAX];

int main () {
    int n;
    scanf(" %d", &n);
    int acc_l = 0, acc_r = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &v[i].l, &v[i].r);    
        acc_l += v[i].l;
        acc_r += v[i].r;
    }
    
    int k = -1, ans = abs(acc_l - acc_r);
    for (int i = 0; i < n; i++) {
        int aux_l = acc_l + v[i].r - v[i].l;
        int aux_r = acc_r + v[i].l - v[i].r;
        if (ans < abs(aux_l - aux_r))
            ans = abs(aux_l - aux_r), k = i;
    }

    if (k == -1) printf("0\n");
    else printf("%d\n", k + 1);
}


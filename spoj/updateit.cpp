#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int v[MAX], bit[MAX];
int t, n, u, l, r, val, q, idx;

void query (int ind) {
    int sum = 0; 
    for (int i = ind; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int update (int idx, int val) {
    
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &u);
        for (int i = 1; i <= n; i++)
            v[i] = 0;
        for (int j = 1; j <= u; j++) {
            scanf ("%d %d %d", &l, &r, &val);
            update (l, r, val);
        }
        for (int i = 0; i < q; i++) {
            scanf ("%d", &idx);
            query (idx);
        }   
    }

}

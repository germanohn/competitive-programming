#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAX = 5 * 1e5 + 5;

int p[MAX], sz[MAX];

int find(int a) {
    if (p[a] == a) return p[a];
    return p[a] = find(p[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) 
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    p[b] = p[a];
}

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    while (m--) {
        int k, a;
        scanf(" %d", &k);
        k--;
        if (k >= 0) {
            scanf(" %d", &a);
            a--;
        }
        while (k > 0 && k--) {
            int b;
            scanf(" %d", &b);
            b--;
            join(a, b);
        }
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", sz[find(i)]);
    }
    printf("\n");
}


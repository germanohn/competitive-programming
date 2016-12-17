#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

struct pto {
    int x, y, r;
};

int n;
int pai[MAX], sz[MAX], ox[MAX], oy[MAX];
pto v[MAX];

int find(int a) {
    if (a == pai[a]) return a;
    return pai[a] = find(pai[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    pai[b] = pai[a];
    sz[a] += sz[b];
}

int main () {
    scanf(" %d", &n);
    memset(ox, -1, sizeof ox);
    memset(oy, -1, sizeof oy);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &v[i].x, &v[i].y);
        pai[i] = i, sz[i] = 1;
        if (ox[v[i].x] == -1) ox[v[i].x] = i;
        if (oy[v[i].y] == -1) oy[v[i].y] = i;
    }
    for (int i = 0; i < n; i++) {
        join(i, ox[v[i].x]);
        join(i, oy[v[i].y]);
    }
    int cont = 0;
    for (int i = 0; i < n; i++) 
        if (i == find(i)) 
            cont++;
    printf("%d\n", cont - 1);
}


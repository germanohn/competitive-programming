#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n, m, q;
int p[2 * MAX], sz[2 * MAX];
map<string, int> mp;

int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = p[a];
}

int main () {
    scanf(" %d %d %d", &n, &m, &q);
    int k = 0;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        mp[a] = k++;
        p[i] = i, sz[i] = 1;
    }
    for (int i = n; i < 2 * n; i++) 
        p[i] = i, sz[i] = 0;
    for (int i = 0; i < m; i++) {
        int t;
        string a, b;
        scanf(" %d", &t);
        cin >> a >> b;
        int sin_a = mp[a], ant_a = mp[a] + n;
        int sin_b = mp[b], ant_b = mp[b] + n;
        if (t == 1) {
            // quero que a e b sejam sinonimos
            if (find(sin_a) == find(ant_b)) {
                printf("NO\n");
            } else {
                printf("YES\n");
                join(sin_a, sin_b);
                join(ant_a, ant_b);
            }
        } else {
            // quero que a e b sejam antonimos
            if (find(sin_a) == find(sin_b)) {
                printf("NO\n");
            } else {
                printf("YES\n");
                join(ant_a, sin_b);
                join(ant_b, sin_a);
            }
        }
    }
    while (q--) {
        string a, b;
        cin >> a >> b;
        int sin_a = mp[a], sin_b = mp[b];
        int ant_b = mp[b] + n;
        if (find(sin_a) == find(sin_b)) printf("1\n");
        else if (find(sin_a) == find(ant_b)) printf("2\n");
        else printf("3\n");
    }
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 5;

int n;
int s[N];
pii v[N];
bool seen[N];
vector<int> adj[N];

int d1(int u, int d, int val) {
    seen[u] = true;
    int _max = 0;
    for (int nx : adj[u]) {
        if (!seen[nx]) {
            if (s[nx] == val)
                _max = max(_max, d);
            _max = max(_max, d1(nx, d + 1, val));
        }   
    }

    return _max;
}

int d2(int u, int d, int best, int val) {
    seen[u] = true;
    if (s[u] == val) best = d;
    for (int nx : adj[u]) {
        if (!seen[nx]) 
            best = max(best, d2(nx, d + 1, best, val));
    }
    return best;
}

void clear() {
    for (int i = 0; i < n; i++)
        seen[i] = false;
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i].ff);
        v[i].ss = i;
        s[i] = v[i].ff;
    }
    sort(v, v + n, greater<pii>());

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (n == 1) {
        printf("%d\n", v[0].ff);
    } else {
        if (v[0].ff != v[1].ff) {
            if (v[0].ff - v[1].ff > 1) {
                printf("%d\n", v[0].ff);
            } else {
                clear();
                int dis = d1(v[0].ss, 1, v[1].ff);
                if (dis == 1) 
                    printf("%d\n", v[0].ff);
                else 
                    printf("%d\n", v[0].ff + 1);
            }
        } else {
            clear();
            seen[v[0].ss] = true;
            int a = 0, b = 0;
            for (int nx : adj[v[0].ss]) {
                if (!seen[nx]) {
                    int dis = d2(nx, 1, 0, v[0].ff);
                    if (dis > a) {
                        b = a, a = dis;
                    } else if (dis > b) 
                        b = dis;
                    
                    if (a < b) swap(a, b);
                }
            }

            if (a + b <= 2) 
                printf("%d\n", v[0].ff + 1);
            else 
                printf("%d\n", v[0].ff + 2);
        }
    }
}


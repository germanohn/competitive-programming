#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 101234;
int c3 = 1, c2 = 1;

struct point3d {
    int x, y, z;
    point3d() {}
    point3d(int x, int y, int z) : x(x), y(y), z(z) {}
    bool operator< (const point3d &o) const {
        if(x == o.x && y == o.y) return z < o.z;
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
};

struct point2d {
    int x, y;
    point2d() {}
    point2d(int x, int y) : x(x), y(y) {}
    bool operator< (const point2d &o) const {
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
};

map<point3d, int> m3;
map<point2d, int> m2;
set<int> adj[N][2];
int done[N][2];

void add_edge(int u, int v, int k) {
    adj[u][k].insert(v);
    adj[v][k].insert(u);
}

bool dfs(int u, int k, int p) {
    if(done[u][k]) return true;
    done[u][k] = 1;
    for(int v : adj[u][k]) {
        if(v == p || v == u) continue;
        if(dfs(v, k, u)) return true;
    }
    return false;
}

int main () {
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int x, y, z, xl, yl, zl;
        scanf("%d %d %d %d %d %d",&x, &y, &z, &xl, &yl, &zl);
        point3d p3a = point3d(x,y,z);
        point3d p3b = point3d(xl,yl,zl);
        point2d p2a = point2d(x,y);
        point2d p2b = point2d(xl,yl);
        int n3a, n3b, n2a, n2b;
        if(!m3[p3a]) m3[p3a] = c3++;
        if(!m3[p3b]) m3[p3b] = c3++;
        if(!m2[p2a]) m2[p2a] = c2++;
        if(!m2[p2b]) m2[p2b] = c2++;
        n3a = m3[p3a]; n3b = m3[p3b];
        n2a = m2[p2a]; n2b = m2[p2b];
        add_edge(n3a, n3b, 0);
        add_edge(n2a, n2b, 1);
    }  
    bool ans2d = false, ans3d = false;
    for(int i = 1; i < c3; i++)
        if(!done[i][0]) ans3d |= dfs(i, 0, -1);
    
    for(int i = 1; i < c2; i++)
        if(!done[i][1]) ans2d |= dfs(i, 1, -1);

    if(ans3d) puts("True closed chains");
    else puts("No true closed chains");

    if(ans2d) puts("Floor closed chains");
    else puts("No floor closed chains");
}


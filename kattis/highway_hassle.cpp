#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int G = 1e5 + 5;
const int inf = 1e9 + 5;

struct tii {
    int d, no, g;

    tii() {}
    tii(int d, int no, int g): d(d), no(no), g(g) {}

    bool operator< (const tii &a) const {
        return d < a.d;
    }
};

int test, n, m, s, t, c, dest, cont;
int d[N], price[N];
int d2[125][G];
bool vis[N];
vector<pii> adj1[N], adj2[N];
vector<int> post;
map<int, int> mp;

void dijkstra1(int u) {
    priority_queue<pii> pq;
    pq.push(pii(0, u));
    d[u] = 0;
    while (!pq.empty()) {
        int x = pq.top().ss;
        pq.pop();
        if (vis[x]) 
            continue;
        vis[x] = true;
        for (pii nx : adj1[x]) {
            if (d[nx.ff] > d[x] + nx.ss) {
                d[nx.ff] = d[x] + nx.ss;
                pq.push(pii(-d[nx.ff], nx.ff));
            } 
        }
    }
}

void dijkstra2() {
    priority_queue<tii> pq;
    pq.push(tii(0, mp[c], 0));
    d2[mp[c]][0] = 0;
    while (!pq.empty()) {
        tii x = pq.top();
        pq.pop();
        if (vis[x.no])
            continue;
        vis[x.no] = true;
        for (pii nx : adj2[x.no]) {
            if (nx.ss > t) 
                continue;
            if (price[x.no] <= price[nx.ff]) {
                printf("x.no %d nx.ff %d d %d\n", x.no, nx.ff);
                int pay = (t - x.g) * price[x.no];
                int rest = t - nx.ss;
                if (d2[nx.ff][rest] > d2[x.no][x.g] + pay) {
                    d2[nx.ff][rest] = d2[x.no][x.g] + pay;
                    pq.push(tii(-d2[nx.ff][rest], nx.ff, rest));
                }
            } else {
                if (x.g > nx.ss) 
                  continue;
                printf("x.g %d\n", x.g);
                int pay = (nx.ss - x.g) * price[x.no];
                if (d2[nx.ff][0] > d2[x.no][x.g] + pay) {
                    if (x.no == 1 && nx.ff == 3) {
                        printf(":: d.x %d d.nx %d pay %d\n", d2[x.no][x.g], d2[nx.ff][0], pay);
                    }
                    d2[nx.ff][0] = d2[x.no][x.g] + pay;
                    pq.push(tii(-d2[nx.ff][0], nx.ff, 0));
                }  
            }
        }
    }
}

void clear() {
    for (int i = 0; i < n; i++) {
        d[i] = inf;
        vis[i] = false;
    }
}

int main () {
    scanf(" %d", &test);
    while (test--) {
        scanf(" %d %d %d %d", &n, &m, &s, &t);
        cont = 0;
        for (int i = 0; i < n; i++) {
            adj1[i].clear();
            adj2[i].clear();
        }
        post.clear();
        mp.clear();
        for (int i = 0; i < m; i++) {
            int a, b, f;
            scanf(" %d %d %d", &a, &b, &f);
            a--, b--;
            adj1[a].pb(pii(b, f));
            adj1[b].pb(pii(a, f));
        }
        for (int i = 0; i < s; i++) {
            int x, p;
            scanf(" %d %d", &x, &p);
            x--;
            post.pb(x);
            if (mp[x] == 0) mp[x] = cont++;
            price[mp[x]] = p;
        }
        scanf(" %d %d", &c, &dest);
        c--, dest--;
        if (mp[dest] == 0) {
            mp[dest] = cont++;
            //price[mp[dest]] = inf;
        }

        for (int i = 0; i < post.size(); i++) {
            printf("root %d\n", post[i]);
            clear();
            int u = post[i];
            dijkstra1(u);
            /*for (int i = 0; i < n; i++) {
                printf("i %d d %d\n", i + 1, d[i]);
            }
            printf("\n");*/
            for (int j = 0; j < post.size(); j++) {
                int v = post[j];
                if (u == v) 
                    continue;
                printf("aresta entre %d e %d d %d\n", u, v, d[v]);
                adj2[mp[u]].pb(pii(mp[v], d[v]));
            }
            printf("aresta entre %d e %d d %d\n", u, dest, d[dest]);
            adj2[mp[u]].pb(pii(mp[dest], d[dest]));
        }

        clear();
        for (int i = 0; i < s + 1; i++) {
            for (int j = 0; j < G; j++)
                d2[i][j] = inf;
        }
        dijkstra2();
        for (int i = 0; i < n; i++) {
            printf("post %d d %d\n", post[i], d2[mp[post[i]]][0]);
        }
        int ans = inf;
        for (int i = 0; i <= t; i++) {
        //    printf("t %d d2 %d\n", i, d2[mp[dest]][i]);
            ans = min(ans, d2[mp[dest]][i]);
        }
        printf("%d\n", ans);
        printf("%d\n", d2[mp[dest]][0]);
    }
}


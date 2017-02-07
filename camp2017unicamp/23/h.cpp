#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 400005;

int n, cont_e, turn, new_color;
int color[MAX], sz[MAX], seen[MAX];
int to[MAX], hd[MAX], nx[MAX];
bool mark[MAX];
map<pii, int> mp;

int find(int &e) {
    if (e == -1 || !mark[e]) return e;
    else return e = find(nx[e]);
}

void paint(int u, int label) {
    sz[color[u]]--;
    color[u] = label;
    sz[color[u]]++;
    for (int e = find(hd[u]); e != -1; e = find(nx[e])) {
        int v = to[e];
        if (color[v] != color[u])
            paint(v, color[u]);
    }
}

void join(int a, int b) {
    if (sz[color[a]] < sz[color[b]]) swap(a, b);
    paint(b, color[a]);

    // com esse swap, nao preciso mapear (a, b) e (b, a), porque saberei que (b, a)
    // tera valor cont_e + 1
    if (a > b) swap(a, b);
    mp[pii(a, b)] = cont_e;

    // criando aresta (a, b) e (b, a)
    to[cont_e] = b; nx[cont_e] = hd[a]; hd[a] = cont_e++;
    to[cont_e] = a; nx[cont_e] = hd[b]; hd[b] = cont_e++; 
}

void parallel_dfs(int a, int b) {
    stack<pii> st[2];
    st[0].push(pii(a, find(hd[a])));
    st[1].push(pii(b, find(hd[b])));
    bool round = false;
    turn++;
    while (!st[round].empty()) {
        pii top = st[round].top();
        int u = top.ff, e = find(top.ss);
        st[round].pop();
        seen[u] = turn;
        while (e != -1 && seen[to[e]] == turn) 
            e = find(nx[e]);
        if (e == -1) 
            continue;
        int v = to[e];
        seen[v] = turn;
        top.ss = find(nx[e]);
        st[round].push(top);
        st[round].push(pii(to[e], hd[v]));
        round = !round;
    }
    if (!round) 
        paint(a, new_color);
    else 
        paint(b, new_color);
    new_color++;
}

void split(int a, int b) {
    if (a > b) swap(a, b);
    int val_e = mp[pii(a, b)];
    mark[val_e] = true, mark[val_e + 1] = true;
    parallel_dfs(a, b);
}

int main () {
    scanf(" %d", &n);
    memset(hd, -1, sizeof hd);
    for (int i = 1; i <= 2 * n; i++) 
        color[i] = i, sz[i] = 1;
    new_color = n + 1;
    char c;
    while (scanf(" %c", &c) && c != 'E') {
        if (c == 'E') 
            break;
        int a, b;
        scanf(" %d %d", &a, &b);
        if (c == 'C') 
            join(a, b);
        else if (c == 'D')
            split(a, b);
        else {
            if (color[a] == color[b]) printf("YES\n");
            else printf("NO\n");
        }
        fflush(stdout);
    }
}


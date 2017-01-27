#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 400005;

int n, new_color, turn, cont;
int color[MAX], seen[MAX], sz[MAX];
int lista[MAX], head[MAX], nx[MAX];
bool mark[MAX];
map<pii, int> mp;

int find(int a) {
    if (a == -1 || !mark[a]) return a;
    return nx[a] = find(nx[a]);
}

void dfs(int u, int rep) {
    sz[color[u]]--;
    color[u] = rep;
    sz[color[u]]++;
    for (int pos = find(head[u]); pos != -1; pos = find(nx[pos])) {
        int v = lista[pos];
        if (color[v] != color[u])
            dfs(v, rep);
    }
}

void join(int a, int b) {
    if (sz[color[a]] < sz[color[b]]) swap(a, b);
    dfs(b, color[a]);

    if (a > b) swap(a, b);
    // inserindo b na lista de adjacencia de a
    mp[pii(a, b)] = cont;
    lista[cont] = b;
    nx[cont] = head[a];
    head[a] = cont++;

    // inserindo a na lista de adjacencia de b
    lista[cont] = a;
    nx[cont] = head[b];
    head[b] = cont++;
}

int split(int a, int b) {
    if (a > b) swap(a, b);
    // marcando as arestas que estao deixando de existir
    int val = mp[pii(a, b)];
    mark[val] = true;
    mark[val + 1] = true;

    stack<pii> st[2];
    st[0].push(pii(a, find(head[a])));
    st[1].push(pii(b, find(head[b])));
    turn++;
    bool round = false;
    while (!st[round].empty()) {
        pii top = st[round].top();
        int e = top.ss;
        st[round].pop();
        seen[top.ff] = turn;
        while (e != -1 && seen[lista[e]] == turn)
            e = find(nx[e]);
        if (e == -1)
            continue;
        pii now = pii(lista[e], find(head[e]));
        top.ss = find(nx[e]);
        st[round].push(top);
        st[round].push(now);
        round = !round;
    }    
    if (!round) 
        dfs(a, new_color);
    else 
        dfs(b, new_color);
    new_color++;
}

int main () {
    scanf(" %d", &n);
    for (int i = 1; i <= 2 * n; i++) 
        color[i] = i, sz[i] = 1;
    memset(head, -1, sizeof head);
    new_color = n + 1;
    char c;
    cont = 1;
    while (scanf(" %c", &c) && c != 'E') {
        if (c == 'E') 
            break;
        int a, b;
        scanf(" %d %d", &a, &b);
        if (c == 'C') 
            join(a, b);
        else if (c == 'D') { 
            split(a, b);
        } else {
            if (color[a] == color[b])
                printf("YES\n");
            else 
                printf("NO\n");
        }
        fflush(stdout);
    }
}


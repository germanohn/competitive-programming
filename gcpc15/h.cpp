#include<bits/stdc++.h>
using namespace std;

const int N = 10004;
int n;
vector<int> adj[N];
bool program[N], vis[N];
map<string, int> id;
int q, ans;

int getid(string s) {
    if(!id.count(s)) id[s] = q++;
    return id[s];
}

void dfs(int u) {
    vis[u] = 1;
    ans--;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

bool is_program(string s) {
    int k = s.length();
    return k >= 9 && s.substr(k-9, k) == "::PROGRAM";
}

void add_edge(string ustr, string vstr) {
    int u = getid(ustr);
    int v = getid(vstr);
    program[u] = is_program(ustr);
    program[v] = is_program(vstr);
    adj[v].push_back(u);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string ustr;
        cin >> ustr;
        int k;
        cin >> k;
        program[getid(ustr)] = is_program(ustr);
        for(int j = 0; j < k; j++) {
            string vstr;
            cin >> vstr;
            add_edge(ustr, vstr);
        }
    }
    ans = n;
    assert(n == q);
    for(int u = 0; u < n; u++) if(program[u] && !vis[u]) dfs(u);
    cout << ans << endl;
}


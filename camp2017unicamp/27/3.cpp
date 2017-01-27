#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define DIR 0
#define FILE 1

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1123456;

struct node {
    int id, type;
    string name;
    node() {}
    node(int id, string name, int type) : id(id), name(name), type(type) {}
};

int w, ts;
char t[99], br[] = "====================";
string res;
vector<node> adj[N];
stack<node> todo;

void fail(){
    puts("IMPOSSIBLE");
    exit(0);
}

int getdep(string s){
    int ret = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '|') ret++;
    return ret;
}

string trim(string s) {
    int i;
    for(i = 0; s[i] == '|' || s[i] == ' ' || s[i] == '-'; i++);
    return s.substr(i);
     
}

void showp(node u, int p, int d, int al) {
    for(int i = 0; i < d; i++)
        res += "| ";
    if(adj[u.id].size() + al <= w) {
        if(u.type == DIR) res += "-";
        res += trim(u.name) + "\n";
        for(node v : adj[u.id]) {
            if(v.id != p)
                showp(v, u.id, d+1, al + adj[u.id].size());
        }
    } else {
        if(u.type == DIR)
            res += "+";
        res += trim(u.name) + "\n";
        if(u.type == DIR)
            todo.push(u);
    }
}


bool isdir(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '-') return true;
        if(s[i] == '.') return false;
    }
    return false;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    scanf("%d", &w);
    stack<node> q;
    scanf(" %[^\n]", t);
    s = t;
    node root = node(ts++, s, DIR);
    q.push(root);
    int dep = 1;
    while(scanf(" %[^\n]", t) != EOF) {
        node n;
        s = t;
        int adep = getdep(s);
        while(dep > adep) {
            q.pop();
            dep--;
        }
        if(isdir(s)) {
            n = node(ts++, s, DIR);
            dep++;
            adj[q.top().id].pb(n);
            q.push(n);
        } else {
            n = node(ts++, s, FILE);
            adj[q.top().id].pb(n);
        }
    }
    todo.push(root);
    int ans = 0;
    while(!todo.empty()) {
        if(adj[todo.top().id].size() > w) fail();
        node f = todo.top();
        todo.pop();
        showp(f, -1, 0, 1);
        res += "====================\n";
        ans++;
    }
    printf("%d\n",ans);
    cout << res;
}


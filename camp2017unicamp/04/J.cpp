#include <bits/stdc++.h>
#define ff first
#define ss second 
#define hash uashe
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

typedef unsigned long long hash;

const int N = 1003;
string train[N];
int ans[N];
map<string, int> f;
hash h[N];
int n, m, l;

void update(hash tgt, int val) {
    for(int i = 0; i < n; i++) 
        if(h[i] == tgt)
            ans[i] = max(ans[i], val);
}

hash get(const string &s) {
    hash x = 33;
    hash h = 0;
    for(int i = 0; i < s.length(); i++)
        h = h * x + (s[i] - '0' + 1);
    return h;
}

int main () {
    scanf("%d %d %d",&n, &l, &m);
    for(int i = 0; i < n; i++) { 
        cin >> train[i];
        f[train[i]]++;
        h[i] = get(train[i]);
    }
    for(int i = 0; i < n; i++) ans[i] = max(ans[i], f[train[i]]);
    while(m--) {
        int a, i, b, j;
        scanf("%d %d %d %d", &a, &i, &b, &j);
        a--; b--; i--; j--;
        f[train[a]]--;
        if(a != b) f[train[b]]--;;
        swap(train[a][i], train[b][j]);
        f[train[a]]++;
        if(a != b) f[train[b]]++;
        h[a] = get(train[a]);
        if(a != b) h[b] = get(train[b]);
        update(h[a], f[train[a]]);
        if(a != b) update(h[b], f[train[b]]);
    }
    for(int i = 0; i < n; i++) printf("%d\n", ans[i]);
}


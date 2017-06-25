#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
const int inf = 1e8;

int n;
int v[N], d[N];
vector<int> adjf[N], adjb[N];

void bfs() {
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x + v[x] < n) {
            for (int nx : adjf[x + v[x]]) {
                if (d[nx] > d[x] + 1) {
                    d[nx] = d[x] + 1;
                    q.push(nx);
                }
            }
        }
        if (x - v[x] >= 0) {
            for (int nx : adjb[x - v[x]]) {
                if (d[nx] > d[x] + 1) {
                    d[nx] = d[x] + 1;
                    q.push(nx);
                }
            }
        }
    }
}

int main() {
    while (scanf(" %d", &n)) {
        if (n == 0) 
            break;
        for (int i = 0; i < n; i++) {
            d[i] = inf;
            adjf[i].clear();
            adjb[i].clear();
        }
        for (int i = 0; i < n; i++) {
            scanf(" %d", &v[i]);
            if (i - v[i] >= 0) 
                adjf[i - v[i]].pb(i);
            if (i + v[i] < n)
                adjb[i + v[i]].pb(i);
        }

        bfs();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] != inf)
                ans = i;
        }

        printf("%d\n", ans);
    }
}

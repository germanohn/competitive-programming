#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int inf = 1e6;
const int N = 3605;

int test, t, n;
int d[N], v[20];
bool vis[N];

void bfs() {
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            int nx = x + v[i];
            if (nx < 0) nx = 0;
            else if (nx > 3600) nx = 3600;

            if (d[nx] > d[x] + 1) {
                d[nx] = d[x] + 1;
                q.push(nx);
            }
        }
    }
}

void clear() {
    for (int i = 0; i <= 3600; i++)
        d[i] = inf;
}

int main() {
    scanf(" %d", &test);
    while (test--) {
        clear();
        scanf(" %d %d", &n, &t);
        for (int i = 0; i < n; i++) 
            scanf(" %d", &v[i]);

        bfs();
        for (int i = t; i <= 3600; i++) {
            if (d[i] != inf) {
                printf("%d %d\n", d[i], i - t);
                break;
            }
        }
    }
}

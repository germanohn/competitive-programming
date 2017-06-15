#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;

int n, m;
bool happy[2][N];
vector<int> eq[2][N];

int main () {
    scanf(" %d %d", &n, &m);
 
    for (int i = 0; i <= n * m; i++) {
        eq[0][i % n].pb(i % m);
        eq[1][i % m].pb(i % n);
    }

    queue<pii> q;
    for (int i = 0; i < 2; i++) {
        int a;
        scanf(" %d", &a);
        for (int j = 0; j < a; j++) {
            int xi;
            scanf(" %d", &xi);
            q.push(pii(xi, i));
        }
    }   

    while (!q.empty()) {
        int xi = q.front().ff; 
        int k = q.front().ss;
        q.pop();

        for (int i = 0; i < eq[k][xi].size(); i++) {
            if (!happy[!k][eq[k][xi][i]]) {
                happy[!k][eq[k][xi][i]] = true;
                q.push(pii(eq[k][xi][i], !k));
            }
        }
    }

    int mod[2] = {n, m};
    bool ok = true;
    for (int i = 0; ok && i < 2; i++) { 
        for (int j = 0; ok && j < mod[i]; j++) {
            if (!happy[i][j])
                ok = false;
        }
    }

    if (ok) printf("Yes\n");
    else printf("No\n");
}

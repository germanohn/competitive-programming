#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n, m, d;
int t[MAX][MAX];
vector<int> v;

int main () {
    scanf(" %d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            scanf(" %d", &t[i][j]);
            v.pb(t[i][j]);
        }
    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        int aux = 0, j;
        for (j = 0; j < v.size(); j++) {
            if (abs(v[i] - v[j]) % d != 0) 
                break;
            aux += (abs(v[i] - v[j]) / d);
        }
        if (j == v.size())
            ans = min(ans, aux);
    }
    if (ans == INT_MAX) printf("-1\n");
    else printf("%d\n", ans);
}


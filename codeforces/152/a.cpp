#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int best[105];
char grade[105][105];

int main () {
    int n, m;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &grade[i][j]);
            best[j] = max(best[j], grade[i][j] - '0');
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool suc = false;
        for (int j = 0; !suc && j < m; j++) {
            if (grade[i][j] == best[j] + '0')
                suc = true;
        }
        if (suc) ans++;
    }
    printf("%d\n", ans);
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int t, n;
char g[2][N];
bool f[2];

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        bool l[2] = {false, false};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %c", &g[i][j]);
                if (g[i][j] == '*')
                    l[i] = true;
            }
            f[i] = false;
        }

        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (g[0][j] == '*' && g[1][j] == '*') {
                if (f[0] || f[1]) 
                    ans++;
                f[0] = f[1] = true;
            } else {
                if (g[0][j] == '*') {
                    if (f[0]) {
                        ans++;
                        f[1] = false;
                    }    
                    f[0] = true;
                } 
                if (g[1][j] == '*') {
                    if (f[1]) {
                        ans++;
                        f[0] = false;
                    }
                    f[1] = true;
                }
            }
        }

        if (l[0] && l[1]) ans++;
        printf("%d\n", ans);
    }
}


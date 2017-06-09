#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;

int n, m;
char t[N][N];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            scanf(" %c", &t[i][j]);

    int ans = 0;
    for (int j = 0; j < m; j++) {
        bool ok = true;
        for (int i = 0; ok && i < n - 1; i++) {
            if (t[i][j] > t[i + 1][j])
                ok = false;
        }
        if (!ok) ans++;
        else 
            break;
    }

    printf("%d\n", ans);
}


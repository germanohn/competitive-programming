#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 505;

int n, m;
char a[MAX][MAX];

int main () {
    scanf(" %d %d", &n, &m);
    int min_x, min_y, mx_x, mx_y;
    min_x = min_y = 2*MAX;
    mx_x = mx_y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'X') {
                min_x = min(min_x, i);
                mx_x = max(mx_x, i);
                min_y = min(min_y, j);
                mx_y = max(mx_y, j);
            }
        }
    }
    bool ans = true;
    for (int i = min_x; ans && i <= mx_x; i++) {
        for (int j = min_y; ans && j <= mx_y; j++) {
            if (a[i][j] == '.')
                ans = false;
        }
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}


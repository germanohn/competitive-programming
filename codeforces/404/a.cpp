#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 305;

int n;
char t[N][N];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            scanf(" %c", &t[i][j]);
    }

    bool ans = true;
    char x = t[0][0];
    for (int i = 0; ans && i < n; i++) {
        if (t[i][i] != x) 
            ans = false;
        if (t[i][n - i - 1] != x) 
            ans = false;
    }

    char y = t[0][1];
    if (y == x) ans = false;
    for (int i = 0; ans && i < n; i++) {
        for (int j = 0; ans && j < n; j++) {
            if (i != j && j != (n - i - 1) && t[i][j] != y) {
                ans = false;
            }
        }
    }

    if (ans) printf("YES\n");
    else printf("NO\n");
}


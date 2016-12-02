#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    int grid[1005][5];
    scanf(" %d", &n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cont = 0;
        for (int j = 0; j < 3; j++) {
            int a;
            scanf(" %d", &a);
            if (a == 1) cont++;
        }
        if (cont >= 2) ans++;
    }

    printf("%d\n", ans);
}


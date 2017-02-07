#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, m, z;
    scanf(" %d %d %d", &n, &m, &z);
    int ans = 0;
    for (int i = 1; i <= z; i++) {
        if (i % n == 0 && i % m == 0) ans++;
    }
    printf("%d\n", ans);
}


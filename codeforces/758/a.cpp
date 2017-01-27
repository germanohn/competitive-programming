#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    sort(v, v + n);
    int mx = v[n - 1];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (mx - v[i]);
    }
    printf("%d\n", ans);
}


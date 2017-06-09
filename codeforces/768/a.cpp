#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 5;

int n;
int v[MAX];

int main () {
    scanf(" %d", &n);
    int mini = 2e9, mx = -1;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        mini = min(mini, v[i]);
        mx = max(mx, v[i]);
    }
    sort(v, v + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mini < v[i] && mx > v[i])
            ans++;
    }
    printf("%d\n", ans);
}


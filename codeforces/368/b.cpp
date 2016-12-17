#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n, m;
int v[MAX], q[MAX];
bool seen[MAX];

int main () {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    if (!seen[v[n - 1]]) q[n - 1]++;
    seen[v[n - 1]] = true;
    for (int i = n - 2; i >= 0; i--) {
        if (!seen[v[i]]) q[i]++;
        seen[v[i]] = true;
        q[i] += q[i + 1];
    }
    for (int i = 0; i < m; i++) {
        int a;
        scanf(" %d", &a);
        a--;
        printf("%d\n", q[a]);
    }
}


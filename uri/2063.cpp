#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int v[105];
bool seen[105];

int mdc(int a, int b) {
    if (a % b == 0) return b;
    return mdc(b, a % b);
}

int main () {
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) 
        scanf(" %d", v + i);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!seen[v[i]]) {
            seen[i] = true;
            int cycleSize = 1;
            int a = v[i];
            while (a != i) {
                seen[a] = true;
                cycleSize++;
                a = v[a];
            }
            ans = (ans / mdc(ans, cycleSize)) * cycleSize;
        }
    }
    printf("%d\n", ans);
}


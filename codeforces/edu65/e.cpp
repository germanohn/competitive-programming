#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;

int v[N];
// minPos[i]: menor posição que o valor i aparece em v
int minPos[N];
// minAccPos[i]: menor posição que um valor em [i, x] aparece em v
int minAccPos[N];
// maxPos[i]: maior posição que o valor i aparece em v
int maxPos[N];
// maxAccPos[i]: maior posição que um valor em [1, i] aparece em v
int maxAccPos[N];

int main() {
    int n, x;
    scanf(" %d %d", &n, &x);

    for (int i = 0; i <= x; i++) {
        minPos[i] = N;
        maxPos[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        if (minPos[v[i]] == N) {
            minPos[v[i]] = i;
        }
        maxPos[v[i]] = i;
    }

    minAccPos[x] = minPos[x];
    for (int i = x - 1; i >= 1; i--) {
        minAccPos[i] = min(minPos[i], minAccPos[i + 1]);
    }

    maxAccPos[0] = -1;
    for (int i = 1; i <= x; i++) {
        maxAccPos[i] = max(maxPos[i], maxAccPos[i - 1]);
    }

    ll r = max(1, x - 1);
    while(r > 1 && maxPos[r] < minAccPos[r + 1]) {
        r--;
    }
    // r: Nesse ponto r é menor valor em [1, x] em que não existe inversão entre valores de [r + 1, x] em v

    ll ans = x - r + 1;
    for (ll l = 2; l <= x && r <= x && minPos[l - 1] > maxAccPos[l - 2]; l++) {
        while((r < l) || (maxPos[l - 1] > minAccPos[r + 1] && r < x)) {
            r++;
        }
        // propriedade de (l, r): fixado l, r é o menor valor em que não existe inversão entre 
        // valores do conjunto {[1, l - 1] U [r + 1, x]}
        ans += (x - r + 1);
    }

    printf("%lld\n", ans);
}


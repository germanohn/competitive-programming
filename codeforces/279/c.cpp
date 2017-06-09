#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, m;
int v[N];
pii ladder[N];

int main () {
    scanf(" %d %d", &n, &m);
    int k = 1;
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);
    
    bool down = false;
    for (int i = 0; i < n - 1; i++) {
        ladder[i].ff = k;
        if (down && v[i] < v[i + 1])
            k++, down = false;

        if (v[i] > v[i + 1]) down = true;
    }
    ladder[n - 1] = pii(k, k);

    down = false;
    for (int i = n - 2; i >= 0; i--) {
        if (down && v[i] > v[i + 1])
            k--, down = false;
        ladder[i].ss = k;

        if (v[i] < v[i + 1]) down = true;
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        l--, r--;
        if (l != r && ladder[l].ss != ladder[r].ff) 
            printf("No\n");
        else 
            printf("Yes\n");
    }
}


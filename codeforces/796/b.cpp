#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int n, m, k;
int hole[N];

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int h;
        scanf(" %d", &h);
        hole[h] = 1;
    }

    int bone = 1;
    while (k--) {
        int u, v;
        scanf(" %d %d", &u, &v);
        if (hole[bone]) 
            continue;

        if (bone == u) 
            bone = v;
        else if (bone == v)
            bone = u;
    }

    printf("%d\n", bone);
}


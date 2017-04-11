#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int n, m, k;
set<int> hole;

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int h;
        scanf(" %d", &h);
        hole.insert(h);
    }
    int bone = 1;
    bool fall = false;
    if (hole.find(bone) != hole.end())
        fall = true;
    while (k--) {
        int u, v;
        scanf(" %d %d", &u, &v);
        if (!fall) {
            if (bone == u) 
                bone = v;
            else if (bone == v)
                bone = u;

            if (hole.find(bone) != hole.end()) 
                fall = true;
        }
    }

    printf("%d\n", bone);
}


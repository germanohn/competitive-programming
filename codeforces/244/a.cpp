#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, k;
bool own[1000];
vector<int> seg[1000];

int main() {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int a;
        scanf(" %d", &a);
        own[a] = true;
        seg[i].pb(a);
    }

    int l = 1;
    for (int i = 0; i < k; i++) {
        while (seg[i].size() < n) {
            if (!own[l])
                seg[i].pb(l);
            l++;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < seg[i].size(); j++) {
            printf("%d ", seg[i][j]);
        }
        printf("\n");
    }
}

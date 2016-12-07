#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> ans;

int main () {
    int x, y, a, b;
    scanf(" %d %d %d %d", &x, &y, &a, &b);

    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i > j) 
                ans.pb(pii(i, j));
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) 
        printf("%d %d\n", ans[i].ff, ans[i].ss);
}


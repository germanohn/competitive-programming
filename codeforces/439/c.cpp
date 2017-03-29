#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n, k, p;
int a[N];
vector<int> v[2], ans[N];

int main () {
    scanf(" %d %d %d", &n, &k, &p);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        v[a % 2].pb(a);
    }
    
    for (int i = 0; i < k - p; i++) {
        if (!v[1].size()) {
            printf("NO\n");
            return 0;
        }
        ans[i].pb(v[1].back());
        v[1].pop_back();
    }

    for (int i = k - p; i < k; i++) {
        if (v[0].size()) {
            ans[i].pb(v[0].back());
            v[0].pop_back();
        } else if (v[1].size() >= 2) {
            int cont = 0;
            while (cont < 2) {
                ans[i].pb(v[1].back());
                v[1].pop_back();
                cont++;
            }
        } else {
            printf("NO\n");
            return 0;
        }
    }

    while (v[0].size()) {
        ans[0].pb(v[0].back());
        v[0].pop_back();
    } 

    if (v[1].size() % 2 == 1) {
        printf("NO\n");
        return 0;
    } else {
        while (v[1].size()) {
            ans[0].pb(v[1].back());
            v[1].pop_back();
        } 
    }

    printf("YES\n");
    for (int i = 0; i < k; i++) {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}


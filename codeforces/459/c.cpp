#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e3 + 5;

int n, d, k;
vector<int> ans[N];

int main() {
    scanf(" %d %d %d", &n, &k, &d);
    if (k == 1) {
        if (n == 1) {
            for (int i = 0; i < d; i++)
                printf("1\n");
        } else {
            printf("-1\n");
        }
        return 0;
    }
    
    ans[0].pb(1);
    for (int i = 1; i < n; i++) {
        bool carry = true;
        for (int j = 0; j < ans[i - 1].size(); j++) {
            if (carry) {
                if (ans[i - 1][j] < k) {
                    ans[i].pb(ans[i - 1][j] + 1);
                    carry = false;
                } else {
                    ans[i].pb(1);
                }
            } else {
                ans[i].pb(ans[i - 1][j]);
            }
        }
        if (carry) { 
            ans[i].pb(2);
        }
    }

    if (ans[n - 1].size() > d) {
        printf("-1\n");
    } else {
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++) {
                if (i < ans[j].size()) 
                    printf("%d ", ans[j][i]);
                else 
                    printf("1 ");
            }
            printf("\n");
        }
    }
}


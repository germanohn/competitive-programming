#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;

int n, k, p, x, y;
int v[N];
vector<int> ans;

int main () {
    scanf(" %d %d %d %d %d", &n, &k, &p, &x, &y);
    int l = 0, g = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        int cur;
        scanf(" %d", &cur);
        sum += cur;
        if (cur < y) l++;
        else g++;
    }

    if (l >= (n + 1) / 2 || sum > x) {
        printf("-1\n");
    } else {
        while (l + g < n) {
            if (l < n / 2) {
                ans.pb(1);
                sum++;
                l++;
            } else {
                ans.pb(y);
                sum += y;
                g++;
            }
        }

        if (sum <= x) {
            for (int i = 0; i < ans.size(); i++)
                printf("%d ", ans[i]);
            printf("\n");
        } else {
            printf("-1\n");

        }
    }
}


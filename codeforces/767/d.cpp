#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
const int M = 1e7 + 5;

int n, m, k;
int has[N], freq[M];
pii buy[N];

int main () {
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &has[i]);
    for (int i = 0; i < m; i++) {
        scanf(" %d", &buy[i].ff);
        buy[i].ss = i;
    }
    sort(has, has + n, greater<int>());
    int r = has[0];
    for (int i = 0; i < n; i++) {
        if (freq[has[i]] == k) {
            if (r > has[i]) r = has[i];
            while (freq[r] == k && r >= 0)
                r--;
            if (r == -1) {
                printf("-1\n");
                return 0;
            }
            freq[r]++;
        } else 
            freq[has[i]]++;
    }
    sort(buy, buy + m, greater<pii>());
    r = buy[0].ff;
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (freq[buy[i].ff] == k) {
            if (r > buy[i].ff) r = buy[i].ff;
            while (freq[r] == k && r >= 0)
                r--;
            if (r == -1) 
                break;
            ans.pb(buy[i].ss);
            freq[r]++;
        } else {
            freq[buy[i].ff]++;
            ans.pb(buy[i].ss);
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) 
        printf("%d ", x + 1);
    printf("\n");
}


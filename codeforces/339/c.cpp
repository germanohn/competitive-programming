#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int m;
char s[15];
int me[15][15][MAX];
stack<int> ans;
vector<int> w;

int dp(int dif, int last, int left) {
    if (!left) return true;
    if (me[dif][last][left] != -1) return me[dif][last][left];
    for (auto k : w) {
        if (k <= dif || k == last) continue;
        if (dp(k - dif, k, left - 1)) {
            ans.push(k);
            return me[dif][last][left] = 1;
        }
    }
    return me[dif][last][left] = 0;
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %s %d", s, &m);
    for (int i = 0; s[i] != 0; i++) 
        if (s[i] != '0') 
            w.pb(i + 1);
    if (dp(0, 0, m)) {
        printf("YES\n");
        while (!ans.empty()) {
            int a = ans.top();
            ans.pop();
            printf("%d ", a);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
}


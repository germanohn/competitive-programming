#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;
const int MOD = 1e9 + 7;

int n, max_len;
char s[MAX];
int mx[100], me[MAX];

int dp(int i) {
    if (i == n) return 1;
    if (me[i] != -1) return me[i];
    int ans = 0;
    int has = mx[s[i] - 'a'];
    for (int j = i + 1; j <= n; j++) {
        max_len = max(max_len, j - i);
        has--;
        ans = (ans + dp(j)) % MOD;
        if (!has)
            break;
        int nx = s[j] - 'a';
        has = min(has, (mx[nx] - (j - i)));
        if (has <= 0) 
            break;
    }
    return me[i] = ans;
}

int main () {
    memset(me, -1, sizeof me);
    scanf(" %d %s", &n, s);
    s[n] = 'z' + 5;
    mx[s[n] - 'a'] = 2 * MAX;
    for (int i = 0; i < 26; i++) 
        scanf(" %d", &mx[i]);
    printf("%d\n", dp(0));
    printf("%d\n", max_len);
    int cont = 0, l = 0;
    int has = mx[s[0] - 'a'];
    for (int j = 1; j < n; j++) {
        has--;
        if (!has) { 
            cont++, l = j;
            has = mx[s[j] - 'a'];
            continue;
        }
        int nx = s[j] - 'a';
        has = min(has, (mx[nx] - (j - l)));
        if (has <= 0) {
            cont++, l = j;
            has = mx[s[j] - 'a'];
        }
    }
    if (has) printf("%d\n", cont + 1);
    else printf("%d\n", cont);
}


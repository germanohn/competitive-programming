#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n, m, k;
char s[MAX], t[MAX];

int dp(int i, int j, int div) {
    if (div == 0) return 0;
    if (i == n) 
        return div == 0 ? 0 : -INT_MAX;
    if (me[i][div] != -1) return me[i][div];
    for (int l = 
}

int main () {
    scanf(" %d %d %d %s %s", &n, &m, &k, s, t);
    dp(0, k);
}


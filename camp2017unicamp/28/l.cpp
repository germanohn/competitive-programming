#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 5005;

char s[MAX], t[MAX];
int n, m;
bool memo[MAX][MAX][2][2];
bool visi[MAX][MAX][2][2];

bool dp(int i, int j, int f, int g) {
    if(i == n) return j == m;
    if(j == m) return i == n || (f && i == n-1);
    bool &me = memo[i][j][f][g];
    if(visi[i][j][f][g]) return me;
    visi[i][j][f][g] = 1;
    me = 0;
    if(s[i] == t[j] && !f) me |= dp(i, j+1, true, false);
    if(f) {
        if(s[i] != t[j]) me |= dp(i, j+1, true, true);
        if(s[i] == t[j] && g) me |= dp(i, j+1, true, true);
        me |= dp(i+1, j, false, false);
    }
    return me;
}

int main() {
    scanf(" %s %s", s, t);
    n = strlen(s);
    m = strlen(t);
    if (dp(0, 0, 0, 0)) printf("Yes\n");
    else printf("No\n");
}

#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 75;

int len;
ll me[N][15][3][3];
char s[N];

ll dp(int i, int ult, bool fall, bool eq) {
    if (i == len) return 1;
    if (me[i][ult][fall][eq] != -1) return me[i][ult][fall][eq];

    ll ans = 0;
    for (int j = 0; j < 10; j++) {
        if (j > s[i] - '0' && eq) 
            break;
        if (j > ult && fall)
            break;
        ans += dp(i + 1, j, fall | (j < ult), eq & (j == s[i] - '0'));
    }

    return me[i][ult][fall][eq] = ans;
}

int main () {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %s", s);
        len = strlen(s);
        memset(me, -1, sizeof me);

        bool hill = true, fall = false;
        for (int i = 1; hill && s[i] != 0; i++) {
            if (s[i] < s[i - 1]) 
                fall = true;
            if (s[i] > s[i - 1] && fall)
                hill = false;
        }

        if (hill) {
            printf("%lld\n", dp(0, 0, false, true) - 1);
        } else {
            printf("-1\n");
        }
    }
}


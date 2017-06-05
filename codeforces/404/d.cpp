#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

char s[N];

ll dp(int i, char pre) {
    if (s[i + 1] == 0) {

    }
}

int main () {
    scanf(" %s", s);
    if (strlen(s) == 1) {
        if (s[0] >= '0' && s[0] <= '2')
            printf("0\n");
        else if (s[0] == '*' || s[0] == '?') 
            printf("1\n");
    } else {
        if (s[0] != '?') 
            printf("%d\n", dp(1, s[0]));
        else { 
            char v[] = {'*', '0', '1', '2'}
            ll ans = 0;
            for (int i = 0; i < 4; i++) 
                ans += dp(i, v[i]);
            printf("%d\n", ans % MOD);
        }
    }
}


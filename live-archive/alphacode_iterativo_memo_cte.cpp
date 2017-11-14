#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s[0] == '0') 
            break;
        ll dp[3];
        dp[1] = 1, dp[2] = 0;
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[0] = 0;
            } else {
                dp[0] = dp[1];
                if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
                    dp[0] += dp[2];
            }
            dp[2] = dp[1];
            dp[1] = dp[0];
        }

        printf("%lld\n", dp[0]);
    }
}


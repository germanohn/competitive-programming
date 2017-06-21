#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char s[105];

int main () {
    scanf(" %s", s);

    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == 'V' && s[i - 1] == 'V' && (s[i + 1] == 0 || s[i + 1] == 'V')) {
            s[i] = 'K';
            break;
        } else if (s[i] == 'K' && s[i - 1] != 'V' && (s[i + 1] == 0 || s[i + 1] == 'K')) {
            s[i] = 'V';
            break;      
        }
    }

    int ans = 0;
    for (int i = 1; s[i] != 0; i++) {
        if (s[i - 1] == 'V' && s[i] == 'K')
            ans++;
    }

    printf("%d\n", ans);
}


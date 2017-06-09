#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 205;

int k;
char s[N];

int main() {
    scanf(" %s %d", s, &k);
    int len = strlen(s);
    for (int i = len; i < len + k; i++) 
        s[i] = '?';
    int ans = 0;
    for (int i = 0; i < len + k; i++) {
        for (int j = i; j < len + k; j++) {
            int sz = (j - i + 1) / 2;
            bool ok = true;
            for (int l = i; ok && l < i + sz; l++) 
                if (s[l + sz] != '?' && s[l] != s[l + sz])
                    ok = false;
            if (ok)
                ans = max(ans, 2 * sz);
        }
    }
    printf("%d\n", ans);
}

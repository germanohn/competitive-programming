#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

char s[MAX], ans[MAX];

int main () {
    scanf(" %s", s);
    char c = ans[0] = s[0];
    int l = 0, p = 0, n = strlen(s);
    bool appear = false;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] != c) {
            if (i - l >= 2) {
                if (appear) { 
                    ans[p++] = c, appear = false;
                } else 
                    ans[p++] = ans[p++] = c, appear = true;
            } else {
                ans[p++] = c, appear = false;
            }
            c = s[i], l = i;
        }
    }
    if (n - l >= 2) {
        if (appear) 
            ans[p++] = c, appear = false;
        else 
            ans[p++] = ans[p++] = c, appear = true;
    } else {
        ans[p++] = c;
    }
    printf("%s\n", ans);
}


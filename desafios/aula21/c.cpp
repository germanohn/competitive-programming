#include<bits/stdc++.h>
using namespace std;

const int MAX = 2005;
const int inf = 1e9;

int len;
char s[MAX];
int me[MAX][MAX];

int dp(int i, int braces) {
    if (i == len) {
        if (braces == 0) return 0;
        return inf;
    }
    if (me[i][braces] != -1) return me[i][braces];

    int ans = 0;
    if (braces == 0) {
        if (s[i] == '{') {
            ans = dp(i + 1, braces + 1);
        } else {
            ans = 1 + dp(i + 1, braces + 1);
        }
    } else {
        if (s[i] == '{') {
            ans = min(dp(i + 1, braces + 1), 1 + dp(i + 1, braces - 1));
        } else {
            ans = min(1 + dp(i + 1, braces + 1), dp(i + 1, braces - 1));
        }
    }
    return me[i][braces] = ans;
}

int main() {
    int cont = 1;
    while(scanf(" %s", s)) {
        memset(me, -1, sizeof me);
        len = strlen(s);
        if (s[0] == '-') break;
        printf("%d. %d\n", cont++, dp(0, 0));
    }
}

/*
    if (kind == 1) {
        // entao tenho mais abertos
        if (braces - 1 > 0) {
            ans = min(a + dp(i + 1, braces - 1, 1), b + dp(i + 1, braces + 1, 1));
        } else {
            ans = min(a + dp(i + 1, 0, 0), b + dp(i + 1, braces + 1, 1)); 
        }
    } else if (kind == 2) {
        // entao tenho mais fechados

    } else {
        // entao tenho que colocar aberto

    }
*/

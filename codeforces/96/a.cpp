#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    char s[105];
    scanf(" %s", s);
    int c_0, c_1;
    c_0 = 0, c_1 = 0;
    bool ans = false;
    for (int i = 0; !ans && s[i] != 0; i++) {
        if (s[i] == '0') 
            c_0++, c_1 = 0;
        else 
            c_1++, c_0 = 0;
        if (c_1 >= 7 || c_0 >= 7) ans = true;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}


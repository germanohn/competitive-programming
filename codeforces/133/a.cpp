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
    bool ans = false;
    for (int i = 0; !ans && s[i] != 0; i++) {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
            ans = true;
    }

    if (ans) printf("YES\n");
    else printf("NO\n");
}


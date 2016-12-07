#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    char s1[105], s2[105];
    scanf(" %s %s", s1, s2);
    bool ans = true;
    int len = strlen(s1);
    for (int i = 0; ans && s1[i] != 0; i++) {
        if (s1[i] != s2[len - i - 1]) 
            ans = false;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}


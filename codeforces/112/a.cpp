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
    int ans = 0;
    for (int i = 0; !ans && s1[i] != 0; i++) {
        if (tolower(s1[i]) < tolower(s2[i])) {
            ans = -1;
        } else if (tolower(s1[i]) > tolower(s2[i])) {
            ans = 1;
        }
    }
    printf("%d\n", ans);
}


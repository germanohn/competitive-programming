#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

char s[MAX], s2[5] = "RBYG";
int ans[256];

int main () {
    scanf(" %s", s);
    int len = strlen(s);
    for (int i = 0; i + 4 < len; i++) {
        if (s[i] != '!' && s[i + 4] == '!')
            s[i + 4] = s[i], ans[s[i]]++;
    }
    for (int i = len - 1; i > 3; i--) {
        if (s[i] != '!' && s[i - 4] == '!')
            s[i - 4] = s[i], ans[s[i]]++;
    }
    for (int i = 0; i < 4; i++) 
        printf("%d ", ans[s2[i]]);
    printf("\n");
}


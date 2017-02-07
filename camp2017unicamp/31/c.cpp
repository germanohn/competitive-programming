#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

char s[MAX];
int pi[MAX];

int main () {
    scanf(" %s", s);
    int len = strlen(s);
    s[len] = '#';
    for (int i = len + 1; i <= 2 * len; i++) 
        s[i] = s[2 * len - i];
    s[2 * len + 1] = 0;
    len = strlen(s);
    for (int i = 2; i <= len; i++) {
        pi[i] = pi[i - 1];
        while (pi[i] > 0 && s[pi[i]] != s[i - 1]) 
            pi[i] = pi[pi[i]];
        if (s[pi[i]] == s[i - 1])
            pi[i]++;
    }
    printf("%d\n", pi[len]);
}


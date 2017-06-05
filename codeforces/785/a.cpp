#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
char s[100];

int main () {
    scanf(" %d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %s", s);
        if (s[0] == 'T') 
            ans += 4;
        else if (s[0] == 'C')
            ans += 6;
        else if (s[0] == 'O')
            ans += 8;
        else if (s[0] == 'D')
            ans += 12;
        else 
            ans += 20;
    }
    printf("%d\n", ans);
}


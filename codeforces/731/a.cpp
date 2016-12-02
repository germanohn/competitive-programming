#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    char s[105];
    scanf(" %s", s);

    int ans = 0;
    char ant = 'a';
    for (int i = 0; s[i] != 0; i++) {
        char at = s[i];
        if (ant > s[i]) swap(ant, at);
        ans += min(at - ant, ant - 'a' + 'z' - at + 1);
        ant = s[i];
    }

    printf("%d\n", ans);
}


#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, m;
char s[105];

int main() {
    scanf(" %d %d", &n, &m);
    scanf(" %s", s);

    for (int i = 0; i < m; i++) {
        int l, r;
        char c1, c2;
        scanf(" %d %d %c %c", &l, &r, &c1, &c2);
        l--, r--;
        for (int j = l; j <= r; j++) {
            if (s[j] == c1)
                s[j] = c2;
        }
    }

    printf("%s\n", s);
}


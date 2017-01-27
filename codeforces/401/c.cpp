#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
char s[2000005];

int main () {
    scanf(" %d %d", &n, &m);
    if (n - m > 1 || 2 * n + 2 < m) {
        printf("-1\n");
        return 0;
    }
    int p = 0;
    if (n - m == 1) {
        s[p++] = '0';
        n--;
    }
    int cont = 0;
    while (n) {
        if (m >= n && cont < 2) {
            s[p++] = '1';
            m--, cont++;
        } else {
            s[p++] = '0';
            n--, cont = 0;
        }
    }
    while (m)
        s[p++] = '1', m--;
    printf("%s\n", s);
}


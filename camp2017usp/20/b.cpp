#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;
char s[105];

int main () {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %s", s);
        int len = strlen(s);
        if (len == 1) {
            printf("YES\n");
            continue;
        }

        int aux = len;
        while (aux && aux % 2 == 0) {
            aux /= 2;
        }

        if (aux == 1) {
            bool ok = true;
            for (int i = 0; ok && i <= len - 2; i += 2) {
                if (s[i] != 'P' && s[i + 1] != 'P')
                    ok = false;
            }

            if (ok) printf("YES\n");
            else printf("NO\n");
        } else {
            printf("NO\n");
        }
    }
}


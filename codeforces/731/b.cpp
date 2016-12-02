#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int v[200005];

int main () {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);

    bool odd = false;
    for (int i = 0; i < n; i++) {
        if (odd) {
            if (v[i] == 0) {
                printf("NO\n");
                return 0;
            }
            v[i]--;
        }

        if (v[i] % 2 != 0) 
            odd = true;
        else 
            odd = false;
    }

    if (!odd) printf("YES\n");
    else printf("NO\n");
}


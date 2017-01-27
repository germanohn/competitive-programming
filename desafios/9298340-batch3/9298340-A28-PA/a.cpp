#include<bits/stdc++.h>
using namespace std;

int n, t;
int v[50005];

int main() {
    scanf(" %d %d", &n, &t);
    for (int i = 0; i < n - 1; i++) {
        scanf(" %d", &v[i]);
    }

    bool ok = false;
    int now = 0;
    while (!ok && now < n - 1) {
        now += v[now];
        if (now + 1 == t) ok = true;
    }

    if (ok) printf("YES\n");
    else printf("NO\n");
}

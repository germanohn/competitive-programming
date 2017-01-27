#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main () {
    scanf(" %d", &n);
    if (n == 1) {
        printf("YES\n");
        return 0;
    } else if (n == 4) {
        printf("NO\n");
        return 0;
    }
    bool ok = false;
    for (int i = 2; !ok && i * i <= n; i++) {
        if (n % i == 0) 
            ok = true;
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
}


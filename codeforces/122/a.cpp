#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    scanf(" %d", &n);
    bool ans = false;
    for (int i = 4; !ans && i <= n; i++) {
        int aux = i;
        bool lucky = true;
        while (lucky && aux > 0) {
            int dig = aux % 10;
            if (dig != 4 && dig != 7) lucky = false;
            aux /= 10;
        }
        if (lucky && n % i == 0) ans = true;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}


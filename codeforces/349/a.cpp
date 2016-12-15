#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, a = 0, b = 0;
    scanf(" %d", &n);
    bool ans = true;
    for (int i = 0; i < n; i++) {
        int x;
        scanf(" %d", &x);
        if (x == 25) {
            a++;
        } else if (x == 50) {
            a--, b++;
        } else {
            if (b) 
                b--, a--;
            else 
                a -= 3;
        }
        if (a < 0) ans = false;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}


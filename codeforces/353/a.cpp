#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a, b;

int main () {
    scanf(" %d", &n);
    bool l, r;
    l = r = false;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        if (x % 2 != 0) {
            a++;
            if (y % 2 == 0) l = true;
        }
        if (y % 2 != 0) {
            b++;
            if (x % 2 == 0) r = true;
        }
    }
    a %= 2, b %= 2;
    if (!a && !b) printf("0\n");
    else if (a && b && (l || r)) printf("1\n");
    else printf("-1\n");
}


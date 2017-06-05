#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, t, k, d;

int main () {
    scanf(" %d %d %d %d", &n, &t, &k, &d);

    bool f = false;
    int tf = 0;
    while (!f && n > 0) {
        if (tf > d) 
            f = true;
        n -= k;
        tf += t;
    }

    if (f) printf("YES\n");
    else printf("NO\n");
}


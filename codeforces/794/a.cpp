#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a, b, c, n;

int main () {
    scanf(" %d %d %d", &a, &b, &c);
    scanf(" %d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf(" %d", &x);
        if (x > b && x < c) 
            ans++;
    }
    printf("%d\n", ans);
}


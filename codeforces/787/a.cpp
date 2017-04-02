#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e6;

int a, b, c, d;

int main () {
    scanf(" %d %d %d %d", &a, &b, &c, &d);

    int ans = b;
    while (((ans - d) < 0 || (ans - d) % c != 0) && ans <= MAX) 
        ans += a;

    if (ans >= MAX) printf("-1\n");
    else printf("%d\n", ans);
}


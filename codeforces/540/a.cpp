#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;

int n;
char from[N], to[N];

int main () {
    scanf(" %d %s %s", &n, from, to);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        a = from[i] - '0';
        b = to[i] - '0';
        if (a > b) swap(a, b);
        ans += min(b - a, 9 - b + (a + 1));
    }
    printf("%d\n", ans);
}


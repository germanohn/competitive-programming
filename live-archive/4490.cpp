#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;

int dp (int i, int k, int x, int mask) {
    if (
}

int main () {
    while (scanf ("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            v[i] -= 24;
        }
        for (int i = 1; i <= 8; i++) {
            dp (0, k, i, 0);
        }
    }
}


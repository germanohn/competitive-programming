#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, v[1005];

int main () {
    scanf ("%d", &n);
    int x;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x);
        v[x]++;
    }
    for (int i = 0; i < 1002; i++) {
        if (v[i] && v[i+1] && v[i+2]) {
            printf ("YES\n");
            return 0;
        }
    }
    printf ("NO\n");
}

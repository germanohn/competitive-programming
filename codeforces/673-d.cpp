#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k, a, b, c, d;
vector<int> v;

int main () {
    scanf ("%d %d", &n, &k);
    scanf ("%d %d %d %d", &a, &b, &c, &d);
    if (k == n || k == n-1 || n == 4) {
        printf ("-1\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (i != a && i != b && i != c && i != d) {
                v.pb (i);
            }
        }
        printf ("%d %d ", a, c);
        for (int i = 0; i < v.size (); i++) {
            printf ("%d ", v[i]);
        }
        printf ("%d %d\n", d, b);
        printf ("%d %d ", c, a);
        for (int i = 0; i < v.size (); i++) {
            printf ("%d ", v[i]);
        }
        printf ("%d %d\n", b, d);
    }
}


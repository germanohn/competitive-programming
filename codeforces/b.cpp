#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<long long, long long> pii;

int n;
long long a, b, x, y;
vector<pii> v;

int main () {
    scanf ("%d %I64d %I64d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf ("%I64d %I64d", &x, &y);
        v.pb (mp (a*x+y, b*x+y));
    }
    sort (v.begin (), v.end ());
    for (int i = 1; i < n; i++) {
        if (v[i].ss < v[i-1].ss) {
            printf ("YES\n");
            return 0;
        }       
    }
    printf ("NO\n");
}

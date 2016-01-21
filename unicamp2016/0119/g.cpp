#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, pair<int, int> > pii;

set<pii> s;

int main () {
    int x, y, z, xx, yy, zz;
    int a, b, c, n;
    scanf ("%d %d %d %d", &a, &b, &c, &n);
    int area = 2*(a*b + a*c + a*d);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %d", &x, &y, &z);
        s.insert (mp (x, mp (y, z)));
    }
    set<pii> :: iterator it;
    for (it = s.begin (); it == s.end (); it++) {
        xx = (*it
    }
}

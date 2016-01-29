#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main () {
    int n, m, b, a;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &b);
        for (int j = 0; j < b; j++) {
            scanf ("%d", &a);
            s.insert (a);
        }
    }
   if (s.size () == m) printf ("YES\n");
   else printf ("NO\n");
}

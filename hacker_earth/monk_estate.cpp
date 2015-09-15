#include <cstdio>
#include <set>

using namespace std;

set<int> s;

int t, n, a, b;

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        int cont = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &a, &b);
            if (s.find (a) == s.end ()) {
                s.insert (a);
                cont++;
            }
            if (s.find (b) == s.end ()) {
                s.insert (b);
                cont++;
            }
        }
        s.clear ();
        printf ("%d\n", cont);
    }
}

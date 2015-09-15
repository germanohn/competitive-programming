#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define pb push_back

using namespace std;

int n, c, me[200005][2];
vector<int> p;

int pd (int i, int a) {
    if (i == n) return 0;
    if (me[i][a] != -1) return me[i][a];
    if (a == 0) 
        return me[i][a] = max (p[i] +  pd (i + 1, 1), pd (i + 1, 0));
    else 
        return me[i][a] = max (-c -p[i] + pd (i + 1, 0), pd (i + 1, 1));
}

int main () {
    while (scanf ("%d %d", &n, &c) != EOF) {
        memset (me, -1, sizeof (me));
        for (int i = 0; i < n; i++) {
            int a;
            scanf ("%d", &a);
            p.pb (a);
        }
        printf ("%d\n", pd (0, 1));
        p.clear ();       
    }
}

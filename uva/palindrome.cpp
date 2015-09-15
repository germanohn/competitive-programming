#include <bits/stdc++.h>
#define pb push_back
#define MAX 2005

using namespace std;

typedef pair<int, int> pii;
char c[MAX];
pair<int, int> memo[MAX][MAX];
int n;
set<int> s;

pii pd (int l, int k) {
    if (l > k) return pii (0, 0);
    pii &m = memo[l][k];
    if (m.first != -1) return m;
    m = max (pd (l + 1, k), pd (l, k - 1));
    if (c[l] == c[k]) {
        int a = s.find (l+1) != s.end ();
        int b = s.find (k+1) != s.end ();
        pii x = pd (l + 1, k - 1);
        x.first += a + b * (l != k);
        x.second += 1 + (l != k);
        return m = max (x, m);  
    } 
    return m;
}

int main () {
    while (scanf ("%s", c) != EOF) {
        scanf ("%d", &n);
        memset (memo, -1, sizeof (memo));
        int a;
        while (n--) {
            scanf ("%d", &a);
            s.insert (a);
        }
        int tam = strlen (c);
        printf ("%d\n", pd (0, tam - 1).second);
        s.clear ();
    } 
}

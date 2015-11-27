#include <bits/stdc++.h>
using namespace std;

int t, m, n;
map<string, int> m;
map<string, vector<string> > adj;

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d%d", &m, &n);
        for (int i = 0; i < m; i++) {
            scanf (" %s %s", s1, s2);
            if (s1[0] == 'R') lv1 = 0;
            lv2 = lv1+1;
            m[s1] = lv1, m[s2] = lv2;
            adj[s1].pb (s2);
            adj[s2].pb (s1);
        }
    }
}

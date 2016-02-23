#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int z, n, m;
int last[1000005], seq[1000005];

int main () {
    scanf ("%d", &z);
    while (z--) {
        scanf ("%d %d", &n, &m);
        int ate = max (n, m), ans[1000005];
        for (int i = 0; i <= ate; i++)
            last[i] = 0, ans[i] = 0;
        int k = 0, a;
        set<int> s;
        for (int i = 0; i < m; i++) {
            scanf ("%d", &seq[i]);
            if (seq[i] == 0) s.insert (i);
        }
        bool f = true;
        int tam = s.size ();
        for (int i = 0; i < m; i++) {  
            if (seq[i]) {
                a = seq[i];
                set<int>::iterator pos = s.lower_bound (last[a]);
                int t = s.size ();
                if (last[a] > *pos || t == 0 || i < *pos) {
                    f = false;
                    break;
                }
                else  
                    ans[*pos] = a, k++, last[a] = i, s.erase (pos);
            }
        }
        if (f) {
            printf ("YES\n");
            for (int i = 0; i <= m; i++) {
                if (seq[i] == 0) {
                    tam--;
                    if (ans[i] != 0) printf ("%d ", ans[i]);
                    else printf ("0 ");
                }
                if (!tam) break;
            }
            printf ("\n");
        }
        else printf ("NO\n");
    }
}

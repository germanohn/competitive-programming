#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, z, last[1000005];

int main () {
    scanf ("%d", &z);
    while (z--) {
        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) 
            last[i] = 0;
        int a, ans[1000005], cont = 0, k = 0, qz = 0;
        bool f = true;
        stack<int> zero;
        for (int i = 1; i <= m; i++) {
            scanf ("%d", &a);
            if (a > 0) {
                //printf ("b\n");
                if (qz == 0) {
                    f = false;
                    continue;
                }    
                int pos = zero.top ();
                qz--;
                zero.pop ();
                //printf ("c\n");
                if (last[a] < pos) {
                    //printf ("pos %d last[%d] %d i %d\n", pos, a, last[a], i);
                    ans[k] = a, k++, last[a] = i;
                }
                else {
                    //printf ("pos %d i %d\n", pos, i);
                    f = false;
                    break;
                }
            }
            else {
                //printf ("e\n");
                zero.push (i);
                cont++, qz++;
            }
        }
        if (f) {
            printf ("YES\n");
            for (int i = 0; i < cont; i++) {
                if (i < k) printf ("%d ", ans[i]);
                else printf ("0 ");
            }    
            printf ("\n");
        }
        else printf ("NO\n");
    }
}

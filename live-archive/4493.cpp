#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int p, c, x;
int v[5000];

int main () {
    int t = 1;
    while (scanf ("%d %d", &p, &c)) {
        if (p == 0 && c == 0) 
            break;
        printf ("Case %d:\n", t++);
        
        int l = 2005, r = l + (p % 1001);
        for (int i = l; i < r; i++) 
            v[i] = i-l+1;
       
        for (int i = 0; i < c; i++) {
            char com;
            getchar ();
            scanf ("%c", &com);
            if (com == 'N') {
                printf ("%d\n", v[l]);
                v[r] = v[l];
                r++, l++;
            } else {
                scanf ("%d", &x);
                int pos;
                bool find = false;
                for (int j = l; j < r; j++) {
                    if (v[j] == x) {
                        find = true;
                        pos = j;
                    }
                } 
                if (find) {
                    v[l-1] = v[pos];
                    for (int j = pos; j < r-1; j++) 
                        v[j] = v[j+1];
                } else {
                    v[l-1] = x;
                }
                l--, r--;
            }
        }
    }
}

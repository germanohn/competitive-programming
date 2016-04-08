#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

const int MAX = 50005;

int h, r, u, v;
int degree[MAX], degreeR[MAX];
pii vp[MAX];

int main () {
    while (scanf ("%d %d", &h, &r) && h != 0 && r != 0) {
        for (int i = 0; i < r; i++) {
            scanf ("%d %d", &u, &v);
            u--, v--;
            degree[u]++;
            degree[v]++;
        }
        for (int i = 0; i < h; i++) {
            vp[i].ff = degree[i];
            vp[i].ss = i;
        }
        sort (vp, vp+r);
        for (int i = 0; i < r; i++) {
            u = vp[i].ff, v = vp[i].ss;
            if (degree[u] > degree[v]) 
                degreeR[v]++;
            else if (degree[u] < degree[v]) 
                degreeR[u]++;
            else {
                if (u < v) 
                    degreeR[u]++;
                else 
                    degreeR[v]++;
            }
        }
        int i;
        for (i = h-2; i >= 0; i--) {
            if (degreeR[i] != h-i-1) 
                break;
        }
        bool sol = true;
        for (int j = i; j >= 0; j--) {
            if (degreeR[j] != degree[j]) {
                sol = false;
                break;
            }
        }
        if (!sol) printf ("N\n");
        else printf ("Y\n");
    }

}


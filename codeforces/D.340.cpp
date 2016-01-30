#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

pii pto[5];

bool co (pii a, pii b, pii c) {
    if (((ll) (b.ss-a.ss)*(c.ff-a.ff)) == ((ll) (c.ss-a.ss)*(b.ff-a.ff))) return true;
    return false; 
}

bool par (pii a, pii b) {
    return (a.ff == b.ff || a.ss == b.ss);
}

int main () {
    for (int i = 0; i < 3; i++) 
        scanf ("%d %d", &pto[i].ff, &pto[i].ss);
    if (co (pto[0], pto[1], pto[2])) {
        printf ("1\n");
        return 0;
    }
    bool f = false;
    for (int i = 0; i < 3; i++) {
        if (par (pto[i], pto[(i+1)%3])) {
            //printf ("i %d i+1 %d\n", i, (i+1)%3);
            f = true;
            if (pto[i].ss == pto[(i+1)%3].ss) {
                if (pto[i].ff >= pto[(i+1)%3].ff) {
                    if (pto[(i+2)%3].ff > pto[(i+1)%3].ff && pto[(i+2)%3].ff < pto[i].ff) printf ("3\n");
                    else printf ("2\n");
                    return 0;
                }      
                else {
                    if (pto[(i+2)%3].ff > pto[i].ff && pto[(i+2)%3].ff < pto[(i+1)%3].ff) printf ("3\n");
                    else printf ("2\n");
                    return 0;
                }
            }
            if (pto[i].ff == pto[(i+1)%3].ff) {
                if (pto[i].ss >= pto[(i+1)%3].ss) {
                    if (pto[(i+2)%3].ss > pto[(i+1)%3].ss && pto[(i+2)%3].ss < pto[i].ss) printf ("3\n");
                    else printf ("2\n");
                    return 0;
                }
                else {
                    if (pto[(i+2)%3].ss < pto[(i+1)%3].ss && pto[(i+2)%3].ss > pto[i].ss) printf ("3\n");
                    else printf ("2\n");
                    return 0;
                }
            }
        }
    }
    if (!f) printf ("3\n"); 
}

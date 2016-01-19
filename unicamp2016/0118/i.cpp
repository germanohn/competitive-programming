#include <bits/stdc++.h>
#define ff first
#define ss second
#define MAX 2000
using namespace std;
typedef pair<int, int> pii;

pii v[MAX];

int main () {
    int n, accIn = 0, accCon, k = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d %d", &v[i].ff, &v[i].ss);
    sort (v, v+n);
    bool f = false;
    for (int i = 1; i <= 1826; i++) {
        if (i >= v[k].ff && i <= v[k].ss) {
            accIn++;
            if (!f) accCon = 180, f = true;
            if (i == v[k].ss) k++;
        }
        if (f) {
            accCon--;
            if (accIn > 90) {
                printf ("No\n");
                return 0;
            }
            if (accCon == 0) accIn = 0, f = false;
        }
    }
    printf ("Yes\n");
}

#include <bits/stdc++.h>
#define ff first 
#define ss second
using namespace std;
typedef pair<int, int> pii;

int n;
pii v[10];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &v[i].ff, &v[i].ss);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            else {
                if (v[i].ff != v[j].ff && v[i].ss != v[j].ss) {
                    int area = abs (v[i].ff - v[j].ff) * abs (v[i].ss-v[j].ss);
                    printf ("%d\n", area);
                    return 0;
                }
            }
        }
    }
    printf ("-1\n");
}

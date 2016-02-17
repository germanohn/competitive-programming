#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int height[200005], diameter[200005];

int main () {
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) 
            scanf ("%d", &diameter[i]);
        for (int i = 0; i < m; i++) 
            scanf ("%d", &height[i]);
        sort (diameter, diameter + n);
        sort (height, height + m);
        int k = 0;
        ll ans = 0; 
        bool f = false;
        for (int i = 0; i < n; i++) {
            while (k < m && height[k] < diameter[i]) k++;  
            if (k < m) ans += height[k];      
            else {
                f = true;
                printf ("Loowater is doomed!\n");
                break;
            }
            k++; 
        }
        if (!f) printf ("%lld\n", ans);
    }
}

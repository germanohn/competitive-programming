#include <bits/stdc++.h>
using namespace std;

int n, v[100005], ans[100005];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    int maxi = v[n - 1];
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i + 1] > maxi) 
            maxi = v[i + 1];
        if (v[i] > maxi)
           ans[i] = 0;
        else
           ans[i] = abs (v[i] - maxi) + 1; 
    }
    for (int i = 0; i < n; i++) 
        printf ("%d ", ans[i]);
    printf ("\n");
    
}

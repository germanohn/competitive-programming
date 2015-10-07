#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int n, v[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    int mini, maxi;
    printf ("%d %d\n", v[1] - v[0], v[n-1] - v[0]);
    for (int i = 1; i < n - 1; i++) {
         mini = min (v[i] - v[i-1], v[i+1] - v[i]);
         maxi = max (v[i] - v[0], v[n-1] - v[i]);
         printf ("%d %d\n", mini, maxi);
    }
    printf ("%d %d\n", v[n-1] - v[n-2], v[n-1] - v[0]); 
}

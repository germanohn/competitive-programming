#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int v[MAX], ans[MAX];

int main () {
    int n, s;
    scanf ("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf ("%d", &v[i]);
    sort (v, v+n);
    int ind, trip = n, i = 1;
    ans[0] = v[0];
    while (i < n) {
        ind = upper_bound (v+i, v+n, s-v[i-1]) - v;
        if (ind == n) {
            trip--;
            ans[i] = v[i], i++;
        }
        else {
            ans[i] = v[ind];
            v[ind] = v[i], i++;
        }
        if (i != n) {
            ans[i] = v[i], i++;
        }
    }
    printf ("%d\n", trip);
    for (int i = 0; i < n; i++)
        printf ("%d ", ans[i]);
    printf ("\n");
}

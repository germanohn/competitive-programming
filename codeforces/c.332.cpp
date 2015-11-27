#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005; 

int n; 
int h[MAX], ma[MAX], mi[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &h[i]);
    }
    int mini = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (h[i] < mini) 
            mini = h[i];
        mi[i] = mini;
    }
    /*for (int i = 0; i < n; i++) {
        printf ("%d\n", mi[i]);
    }*/
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (h[i] > maxi) 
            maxi = h[i];
        ma[i] = maxi;
    }
    /*for (int i = 0; i < n; i++) {
        printf ("i %d mi %d ma %d\n", i, mi[i+1], ma[i]);
    }*/
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (ma[i] <= mi[i+1]) {
            ans++;
            //printf ("passei\n");
        }
        //printf ("quant\n");
    }
    ans++;
    printf ("%d\n", ans);
}

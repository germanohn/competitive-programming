#include <bits/stdc++.h>
#define end first
#define ini second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, maxi, mark[10005];
pii dish[105];

bool can (int val) {
    int sum;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = dish[i].ini; j < dish[i].end; j++) {
            if (!mark[j] && sum < val) 
                sum++, mark[j] = 1;
        }
        if (sum < val) return false;
    }
    return true;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d %d", &dish[i].ini, &dish[i].end);
    sort (dish, dish+n);
    int lo = 0, hi = 10000;
    while (lo < hi) {
        for (int i = 0; i <= 10000; i++) 
            mark[i] = 0;
        int mid = (lo+hi+1)/2;
        if (can (mid)) {
            lo = mid;
        }
        else {
            hi = mid-1;
        }
    }
    printf ("%d\n", lo*n);
}


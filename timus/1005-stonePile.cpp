#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, v[100005];

int main () {
    int left, right, tot = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) { 
        scanf ("%d", &v[i]);
        tot += v[i];
    }
    int mi = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        left = 0, right = 0;
        for (int j = 0; j < n; j++)  
            if ((i & (1 << j)) > 0)  
                left += v[j]; 
        right = tot-left;
        mi = min (mi, abs (right-left));
    }
    printf ("%d\n", mi);
}


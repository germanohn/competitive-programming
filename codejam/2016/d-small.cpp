#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, k, c, s;

int main () {
    scanf ("%d", &t);
    int test = 1;
    while (t--) {
        scanf ("%d %d %d", &k, &c, &s);
        printf ("Case #%d: ", test++);
        if (s < k) {
            printf ("IMPOSSIBLE\n");
        } else {
            for (int i = 1; i <= k; i++) 
                printf ("%d ", i);
            printf ("\n");
        }
    }
}


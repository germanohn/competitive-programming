#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int v[5], d[5];
int has, need;

int main () {
    scanf ("%d %d %d", &v[0], &v[1], &v[2]);
    scanf ("%d %d %d", &d[0], &d[1], &d[2]);
    for (int i = 0; i < 3; i++) {
        int dif = v[i]-d[i];
        if (dif > 0) 
           has += dif / 2;
        else 
           need -= dif; 
    }
    if (has >= need) 
        printf ("Yes\n");
    else 
        printf ("No\n");
}


#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii v[105];

int main () {
    int n, a;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        v[i].ff = a;
        v[i].ss = i+1;
    }
    sort (v, v+n);
    for (int i = 0; i < n/2; i++) {
        printf ("%d %d\n", v[i].ss, v[n-i-1].ss);
    }
}


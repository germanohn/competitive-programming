#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main () {
    scanf ("%d", &n);
    int ans = n/3;
    if (n == 3*ans) 
        printf ("%d\n", 2*ans);
    else 
        printf ("%d\n", 2*ans+1);
}


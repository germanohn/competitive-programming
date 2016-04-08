#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int pri (int dig) {
    while (dig % 10 == 0) 
        dig / 10;
    return dig;
}

int main () {
    int n;
    while (scanf ("%d", &n) != EOF) {
        int dig = 1;
        for (int i = 2; i <= n; i++) {
            dig = (dig*i);
            dig = pri (dig);
        }
        printf ("%d\n", dig);
    }
}


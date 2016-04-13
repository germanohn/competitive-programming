#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

struct interval {
    int t1, t2, s;
};

int n, m, e;
int me[MAX]
interval inter[MAX];

int dp (int i, int end) {
    if (i == n) 
        return 0;
    if (me[i][end] != -1) return me[i][end];
    int ans;
    ans = dp (i+1, end);
    if (inter[i].t1 <= end && inter[i].t2 > end) 
        ans += dp (i+1, inter[i].t2) + inter[i].s;
    return me[i][end] = ans;
}

int main () {

    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf ("%d %d %d", &inter[i].t1, &inter[i].t2, &inter[i].s);
    sort (inter, inter+n);
    printf ("%d\n", dp (0, 0));
}


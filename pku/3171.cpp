#include <cstdio>
#include <algorithm>
#include <cstring>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1000000000;
const int MAX = 100005;

struct interval {
    int t1, t2, s;
};

int n, m, e;
int me[MAX];
interval inter[MAX];

bool cmp (interval a, interval b) {
    return a.t2 > b.t2;
}
/*
int dp (int i) {
    if (inter[i].t2 == e)
        return 0;
    if (i == n-1)
        return inf;
    if (me[i] != -1) return me[i];
    int ans = inf;
    for (int j = i+1; j < n; j++) {
        if (inter[j].t1 <= inter[i].t2+1 && inter[j].t2 > inter[i].t2)
            ans = min (ans, dp (j) + inter[j].s);
        if (inter[j].t1 > inter[i].t2+1)
            break;
    }
    return me[i] = ans;
}
*/
int main () {   
    memset (me, -1, sizeof me);
    scanf ("%d %d %d", &n, &m, &e);
    for (int i = 0; i < n; i++) 
        scanf ("%d %d %d", &inter[i].t1, &inter[i].t2, &inter[i].s);
    sort (inter, inter+n, cmp);
    /*int ans = inf;
    for (int i = 0; i < n; i++) {
        if (inter[i].t1 == m)
            ans = min (ans, dp (i) + inter[i].s);
        else 
            break;
    }
    */
    int k;
    for (k = 0; k < n; k++) {
        if (inter[k].t2 == e) 
            dp[k] = inter[k].s;
    }
    for (int i = k; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (inter[i].t2 > inter[j].t1)
            if (inter[j].t2 == e) 
                dp[i] = 0;
            if (i == n-1)
                dp[i] = inf;
            dp[i][j] = min (
        }
    }
    if (ans == inf)
        printf ("-1\n");
    else
        printf ("%d\n", ans);
}


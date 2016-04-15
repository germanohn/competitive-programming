#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1123456;

int n, d;
int day[MAX], ans[MAX];
bool mark[MAX];
pii h[MAX];

bool cmp (pii a, pii b) {
    return a > b;
}

bool cmp2 (int a, int b) {
    return a > b;
}

int main () {
    int tc, n, d;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &d);
        for (int i = 0; i < n; i++) {
            scanf (" %d", &h[i].ff);
            h[i].ss = i;
            mark[i] = false;
        }
        for (int i = 0; i < d; i++)
            scanf (" %d", &day[i]);
        sort (h, h + n, cmp);
        sort (day, day + d, cmp2);
        int j = 0, sum = 0;
        for (int i = 0; i < d; i++) {
            while (j < n && h[j].ff > day[i]) {
                sum++;
                mark[h[j].ss] = true;
                int l, r;
                l = h[j].ss-1;
                r = h[j].ss+1;
                if (n > 1 && h[j].ss == 0) {
                    if (mark[r])
                        sum--;
                } else if (n > 1 && h[j].ss == n-1) {
                    if (mark[l]) 
                        sum--;
                } else if (n > 1) {
                    if (mark[r])
                        sum--;
                    if (mark[l])
                        sum--;
                }
                j++;
            }
            ans[d-i-1] = sum;           
        }
        for (int i = 0; i < d-1; i++)
            printf ("%d ", ans[i]);
        printf ("%d\n", ans[d-1]);
    }
}

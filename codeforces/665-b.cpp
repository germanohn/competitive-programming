#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, item;
int v[105], inv[105];

int main () {
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf ("%d", &inv[i]);
        v[inv[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            scanf ("%d", &item);
            int ind;
            ans += v[item];
            for (int l = 1; l <= k; l++) {
                if (v[l] == item) {
                    ind = l;
                    break;
                }
            }
            int tmp = v[ind];
            for (int l = ind; l >= 2; l--) 
                v[l] = v[l-1];
            v[1] = tmp;
        }
    }
    printf ("%d\n", ans);
}


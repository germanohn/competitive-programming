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
int v[1005], freq[1005];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
    }
    sort (v, v+n);
    int now = v[0], k = 0;
    freq[0]++;
    for (int i = 1; i < n; i++) {
        if (now != v[i]) {
            freq[++k]++;
            now = v[i];
        } else {
            freq[k]++;
        }
    }
    int j = 0;
    bool f = true;
    while (f) {
        f = false;
        for (int i = 0; i <= k; i++) {
            if (freq[i] > 0) {
                f = true;
                v[j] = i;
                j++;
                freq[i]--;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i-1])
            ans++;
    }
    printf ("%d\n", ans);
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, p;
int v[15], st;

int main () {
    while (scanf ("%d %d", &n, &p) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
        }
        int ac, penalty, acc;
        ac = penalty = acc = 0;
        if (v[p] <= 300) {
            ac++;
            penalty += v[p];
            acc += v[p];
        } else {
            printf ("0 0\n");
            continue;
        }
        int tmp = v[p];
        v[p] = v[0];
        v[0] = tmp;
        sort (v+1, v+n);
        for (int i = 1; i < n; i++) {
            if (v[i]+acc <= 300) {
                ac++;
                penalty += v[i]+acc;
                acc += v[i];
            }
        }
        printf ("%d %d\n", ac, penalty);
    }
}


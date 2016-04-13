#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int v[85];
bool mark[85];

int main () {
    while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
        for (int i = 0; i < n; i++) 
            mark[i] = false;
        for (int i = 0; i < n; i++) { 
            scanf ("%d", &v[i]);
            v[i]--;
        }
        int q = 0;
        while (q < n) {
            int i;
            for (i = 0; i < n; i++) {
                if (!mark[i]) {
                    mark[i]
                }
            }
        }
    }
}


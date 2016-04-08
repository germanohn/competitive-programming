#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 300005;

int n, k;
int v[MAX];

int main () {
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    int l, r, j = -1;
    int ans = -1, qZeros = 0;
    for (int i = 0; i < n && j < n; i++) {
        while (qZeros <= k && ++j < n) {
            if (v[j] == 0) 
                qZeros++;
        }
        if (j-i > ans) {
            ans = j-i;
            l = i;
            r = j-1;
        }
        if (v[i] == 0) {
            qZeros--;
        }
    }
    printf ("%d\n", ans);
    for (int i = l; i <= r; i++) 
        v[i] = 1;
    for (int i = 0; i < n; i++) {
        printf ("%d ", v[i]);
    }
    printf ("\n");
}


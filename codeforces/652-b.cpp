#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n;
int v[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &v[i]);
    sort (v, v+n);
    int ans[MAX], l, r;
    l = 0, r = n-1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans[i] = v[l++];
        } else {
            ans[i] = v[r--];
        }
    }
    bool f = true;
    for (int i = 1; f && i < n; i++) {
        if (i % 2 != 0 && ans[i] < ans[i-1]) {
            f = false;
        }
        if (i % 2 == 0 && ans[i] > ans[i-1]) {
            f = false;
        }
    }

    if (!f) {
        printf ("Impossible\n");
    } else {
        for (int i = 0; i < n; i++)
            printf ("%d ", ans[i]);
        printf ("\n");
    }
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int k, n, waste, ans;
int tree[4*MAX];

void query (int l, int r, int no, int v) {
    if (l == r) {
        // cheguei em uma folha
        tree[no] += v;    
        return;
    }   
    int mid = (l+r)/2;
    if (k - tree[2*no] >= v) {
        query (l, mid, 2*no, v);
    } else {
        query (mid+1, r, 2*no + 1, v);
    }
    tree[no] = min (tree[2*no], tree[2*no + 1]);
}

void query (int v) {
    query (0, n-1, 1, v);
}

int solve (int l, int r, int no) {
    if (l == r) {
        if (tree[no] == 0) {
            return 0;
        } else {
            waste += (k - tree[no]);
            return 1;
        }
    }
    int mid = (l+r)/2;
    int ans = solve (l, mid, 2*no) + solve (mid+1, r, 2*no + 1);
    return ans;
}

int main () {
    int v, a, b;
    bool f = false;
    while (scanf ("%d %d", &k, &n) != EOF) {
        if (f) printf ("\n");
        f = true;
        waste = 0;
        for (int i = 0; i <= 4*n; i++) 
            tree[i] = 0;
        getchar ();
        for (int i = 0; i < n; i++) {
            char str[50];
            gets (str);
            if (str[0] == 'b') {
                sscanf (str, "b %d %d", &a, &v);
                i += a-1;
            }
            else {
                sscanf (str, "%d", &v);
                a = 1;
            }
            for (int j = 0; j < a; j++) 
                query (v); 
        }
        ans = solve (0, n-1, 1);
        printf ("%d %d\n", ans, waste);
    }
}

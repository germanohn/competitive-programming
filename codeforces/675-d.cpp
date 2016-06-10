#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 5;

struct tree {
    int val;
    int pai;
    int left, right;
};

int n;
tree hd[MAX];
int es;
int root;
int v[MAX];

int put (int no, int x, int pai) {
    if (no == -1) {
        no = es++;
        hd[no].pai = pai;
        hd[no].left = hd[no].right = -1;
        hd[no].val = x;
    } else if (x > hd[no].val) {
        hd[no].right = put(hd[no].right, x, no);
    } else {
        hd[no].left = put(hd[no].left, x, no);
    }
    return no;
}

int get (int no, int x) {
    if (hd[no].val == x) {
        return hd[no].pai;
    }
    int pai;
    if (x > hd[no].val)
        pai = get (hd[no].right, x);
    else 
        pai = get (hd[no].left, x);
    return pai;
}

int main () {
    scanf ("%d", &n);
    root = -1;
    printf ("oi\n");
    es = 1;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i]);
        root = put (root, v[i], -1);
    }
    for (int i = 1; i < n; i++) {
        int pai = get (root, v[i]);
        printf ("%d\n", hd[pai].val);   
    }
}


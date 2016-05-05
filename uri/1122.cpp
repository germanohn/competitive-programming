#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 40500;

int n, f, turn;
int vis[45][2*MAX], status[45], v[45];

int dp (int i, int fluxo) {
    if (i == n) {
        if (fluxo == f) {
            return 1;
        } else {
            return 0;
        }
    }
    if (vis[i][fluxo+MAX] == turn) return vis[i][fluxo+MAX];
    vis[i][fluxo+MAX] = turn;
    int st = 0;
    if (dp (i+1, fluxo+v[i])) st |= 1;
    if (dp (i+1, fluxo-v[i])) st |= 2;
    status[i] |= st;
    return !!st;
}

int main () {
    turn = 1;
    while (scanf ("%d %d", &n, &f) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            status[i] = 0;
        }
        if (dp (0, 0)) {
            for (int i = 0; i < n; i++) {
                if (status[i] == 1) {
                    printf ("+");
                } else if (status[i] == 2) {
                    printf ("-");
                } else if (status[i] == 3) {
                    printf ("?");
                }
            }
            printf ("\n");
        } else {
            printf ("*\n");
        }
        turn++;
    }
}


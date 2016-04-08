#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1005;

int n, ans;
int ax, ay, bx, by;

int cross (int x1, int y1, int x2, int y2) {
    return x1*y2 - y1*x2;
}

int main () {
    scanf ("%d", &n);
    scanf ("%d %d %d %d", &ax, &ay, &bx, &by);
    int x1, x2, y1, y2;
    x1 = bx-ax, y1 = by-ay;
    for (int i = 0; i < n-2; i++) {
        ax = bx, ay = by;
        scanf ("%d %d", &bx, &by);
        x2 = bx-ax, y2 = by-ay;
        if (cross (x1, y1, x2, y2) > 0)
            ans++;
        x1 = x2, y1 = y2;
    }
    printf ("%d\n", ans);
}

/*
const int MAX = 1005;

int n;
char sent;

int main () {
    scanf ("%d", &n);
    int ax, ay, bx, by, ans = 0;
    scanf ("%d %d %d %d", &ax, &ay, &ax, &ay);
    sent = 'N';
    for (int i = 0; i < n-2; i++) {
        scanf ("%d %d", &bx, &by);
        char dir;
        if (ax == bx) {
            if (by > ay)
                dir = 'N';
            else 
                dir = 'S';
        } else {
            if (bx > ax)
                dir = 'E';
            else 
                dir = 'W';           
        }
        if (sent == 'N') {
            if (dir == 'W')
                ans++;
        } else if (sent == 'E') {
            if (dir == 'N')
                ans++;
        } else if (sent == 'S') {
            if (dir == 'E')
                ans++;
        } else {
            if (dir == 'S')
                ans++;
        }    
        sent = dir, ax = bx, ay = by;
    }
    printf ("%d\n", ans);
}
*/

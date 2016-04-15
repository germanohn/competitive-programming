#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1123456789;

int n, v[10], d[305];
queue<int> q;

void bfs () {
    q.push (0);
    d[100] = 0;
    while (!q.empty ()) {
        int u = q.front ();
        q.pop ();
        for (int i = 0; i < 6; i++) {
            int v1 = u-v[i], v2 = u+v[i];
            if (v1 >= -100 && v2 <= 200 && d[v1+100] == -1) {
                d[v1+100] = d[u+100]+1;
                q.push (v1);
            } 
            if (v2 >= -100 && v2 <= 200 && d[v2+100] == -1) {
                d[v2+100] = d[u+100]+1;
                q.push (v2);
            }
        }
    }
}

int main () {
    scanf ("%d", &n);
    while (n--) {
        for (int i = 0; i < 6; i++) 
            scanf ("%d", &v[i]);
        for (int i = 0; i < 305; i++) 
            d[i] = -1;
        bfs ();
        double ans = 0;
        int mx = -1;
        for (int i = 1; i <= 100; i++) {
            mx = max (mx, d[i+100]);
            ans += d[i+100];
        }
        printf ("%.2lf %d\n", ans/100, mx);
    }
}

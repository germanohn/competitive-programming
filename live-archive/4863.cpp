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

struct team {
    int k, da, db;
};

int N, A, B, k, da, db;
team v[MAX];

bool compare (team a, team b) {
    return abs (a.da - a.db) > abs (b.da - b.db); 
}

int main () {
    while (scanf ("%d %d %d", &N, &A, &B)) {
        if (N == 0 && A == 0 && B == 0)
            break;
        for (int i = 0; i < N; i++) {
            scanf ("%d %d %d", &k, &da, &db);
            v[i].k = k, v[i].da = da, v[i].db = db;
        }
        sort (v, v + N, compare);
        
        int mi, ans = 0;
        for (int i = 0; i < N; i++) {
            mi = min (v[i].da, v[i].db);
            if (mi == v[i].da) {
                if (v[i].k <= A) {
                    ans += v[i].k * mi;
                    A -= v[i].k;
                } else {
                    ans += A * mi;
                    v[i].k -= A;
                    A = 0;
                    B -= v[i].k;
                    ans += v[i].k * v[i].db;
                }
            } else {
                if (v[i].k <= B) {
                    ans += v[i].k * mi;
                    B -= v[i].k;
                } else {
                    ans += B * mi;
                    v[i].k -= B; 
                    B = 0;
                    A -= v[i].k;
                    ans += v[i].k * v[i].da;
                }
            }
        }
        printf ("%d\n", ans);
    }
}


#include <cstdio>
#include <vector>
#include <climits>
#include <string>
#include <map>
#define pb push_back
#define mp make_pair

using namespace std;

int t, n, b, price, qua;
string type, name;
char c[25], cc[25];
vector<pair<int, int> > A[1005];

map<string, int> m;

bool compra (int val, int comp) {
    int quant = 0, custo = b;
    for (int i = 0; i < comp; i++) {
        int mini = INT_MAX;
        for (int j = 0; j < A[i].size (); j++) {
            if (A[i][j].second >= val) 
                mini = min (A[i][j].first, mini);
        }
        custo -= mini;
        if (custo >= 0)
            quant++;
        //printf ("%d\n", custo);
    }
     //   printf ("custo %d comp %d quant %d\n", custo, comp, quant);
    if (quant == comp) return true;
    return false;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &b);
        for (int i = 0; i <= n; i++) 
            A[i].clear ();
        m.clear ();
        int k = 0, lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; i++) {
            scanf ("%s %s %d %d", c, cc, &price, &qua);
            type = c;
            if (qua > hi) hi = qua;
            if (qua < lo) lo = qua;

            if (m.find (type) == m.end ()) m[type] = k++;
            A[m[type]].pb (mp (price, qua));
        }
 //       printf ("lo %d  hi %d\n", lo, hi);
        while (lo != hi) {
            int mid = (lo + hi + 1) / 2;
   //         printf ("mid %d\n", mid);
            if (compra (mid, k)) { 
                lo = mid;         
 //               printf ("passei\n");
            }    
            else
                hi = mid - 1;
        }
        printf ("%d\n", lo);
    }
}

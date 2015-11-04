#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int n, m, ff, ss, tt;
int A[105][105];
vector<pii> par;

int main () {
    scanf ("%d %d", &n, &m);
    int a, b, q;
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++)
            A[i][j] = 0; 
    ff = 1, ss = 2, tt = 3;
    for (int i = 0; i < m; i++) {
        scanf ("%d %d %d", &a, &b, &q);
        par.pb (mp (a, b));
        A[a][b] = q;
        A[b][a] = q;
    }
    int maxi = -1, tmp = 0;
    for (int i = 0; i < par.size (); i++) {
        a = par[i].first;
        b = par[i].second;
        for (int j = 1; j <= n; j++) {
            if (j != a && j != b) {
                tmp = A[a][b] + A[a][j] + A[b][j];
                if (tmp > maxi) {
                    ff = a;
                    ss = b;
                    tt = j;
                    maxi = tmp;
                } 
            }
        }
    }
    printf ("%d %d %d\n", ff, ss, tt);
}

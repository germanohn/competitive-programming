#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, m;
set<int> row, col;

int main () {
    cin >> n >> m;
    ll ans = n*n;
    ll x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (row.find (x) == row.end ()) {
            ans = ans - (n-col.size ());
            row.insert (x);
        } 
        if (col.find (y) == col.end ()) {
            ans = ans - (n-row.size ());
            col.insert (y); 
        }
        cout << ans << " ";
    }
    printf ("\n");
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;


int main () {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > gain;
    ull totEnemies = 0;
    int a, b;
    for(int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        totEnemies += a;
        int qntFull = a/b;
        gain.pb(mp(b, qntFull));
        if(a - qntFull*b > 0)
            gain.pb(mp(a - qntFull*b, 1));
    }
    int avail = d;
    sort(gain.rbegin(), gain.rend());
    ull soma = 0;
    for(auto v : gain)
    {
        if(avail == 0) break;
        if(v.ss >= avail)
        {
            soma += avail*v.ff;
            avail = 0;
        }
        else
        {
            soma += v.ss * v.ff;
            avail -= v.ss;
        }
    }
    cout << totEnemies - soma << endl;
    return 0;
}


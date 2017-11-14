#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int minih = 1000000007, maxih = 0;
        int miniw = 1000000007, maxiw = 0;
        vector<pii> wv;
        vector<pii> hv;
        for (int i = 0; i < n; i++) {
            pii w, h;
            cin >> w.ff >> w.ss >> h.ff >> h.ss;
            minih = min(minih, h.ff);
            maxih = max(maxih, h.ss);
            miniw = min(miniw, w.ff);
            maxiw = max(maxiw, w.ss);

            wv.pb(w);
            hv.pb(h);
        }
        int ok = false;
        for (int i = 0; i < n; i++) {
            if (minih == hv[i].ff && maxih == hv[i].ss && miniw == wv[i].ff && maxiw == wv[i].ss) {
                cout << "ANO" << endl;
                ok = true;
            }
            if (ok) break;
        }
        if (!ok) cout << "NIE" << endl;
    }

}


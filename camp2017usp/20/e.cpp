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
    while(t--){
        int n;
        cin >> n;
        vector<int> w(n-1);
        vector<int> h(n);
        ll war1 = 0;
        cin >> war1;
        for(int i = 0; i < n-1; ++i) cin >> w[i];
        for(int i = 0; i < n; ++i) cin >> h[i];
        sort(w.begin(), w.end());
        sort(h.rbegin(), h.rend());
        war1 *= h[0];
        bool ok = true;
        for(int i = 0; i < n-1; ++i)
        {
            if(w[i] * h[i+1] >= war1){
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


#include <bits/stdc++.h>

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define ins insert
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    cin >> n;
    set<ll> h;
    ll best = 1e18;
    vector<ll> vec(n);
    for(int i = 0; i < n; ++i){
        cin >> vec[i];
        h.insert(vec[i]); 
    }

    for(int i = 0; i < n-1; ++i)
    {
        //h.erase(h.find(vec[i]));
        auto it = h.lower_bound(vec[i]);
        if(it == h.begin()){
            continue;
        }
        else{
            it = prev(it);
            if(vec[i] - *it < best)
                best = vec[i] - *it;
        }
        h.erase(h.find(vec[i]));
    }
    cout << best << endl;
}


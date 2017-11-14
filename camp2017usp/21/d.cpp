#include <bits/stdc++.h>
#define fi first
#define se second 
#define pb push_back
#define mt make_tuple
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main () {
    ll n, m, b, x;
    cin >> n >> m;
    vector<tuple<ll, ll, ll> > s(n);
    set<pair<ll, ll>, greater<pair<ll, ll> > > lo;
    set<pair<ll, ll>, greater<pair<ll, ll> > > hi;
    for(int i = 0; i < n; ++i){
        cin >> b >> x;
        s[i] = mt(b, i, x);
        if(x != 1) hi.insert(mp(b, i));
        else lo.insert(mp(b,i));
    }
    int min = 0;
    ll accu = 0;
    sort(s.rbegin(), s.rend());
    set<tuple<ll, ll, ll> > optLo;
    set<tuple<ll, ll ,ll> > optHi;
    vector<tuple<ll, ll, ll> > opt;
    for(int i = 0; i < n; ++i)
    {
        if(accu >= m) break;
        else{
            if(get<2>(s[i]) != 1)
               optHi.insert(s[i]);
            else
               optLo.insert(s[i]); 
            accu += get<0>(s[i]);
            min++;
            opt.pb(s[i]);
        }
    }
    ll curResp = accu;
    for(auto v : optLo)
    {
        lo.erase(lo.find(mp(get<0>(v), get<1>(v))));
    }
    //sort(optHi.begin(), optHi.end());
    vector<tuple<ll, ll, ll> > toErase;
    for(auto &v : optHi)
    {
        if(!lo.empty())
        {
            auto cand = *(lo.begin());
            ll diff = cand.fi - get<0>(v);
            if(curResp + diff >= m){
                toErase.push_back(v);
                optLo.insert(mt(cand.fi, cand.se, 0ll));
                curResp += diff;
                lo.erase(lo.begin());
            }
            else break; 
        }
        else break; 
    }
    for(int i = 0; i < (int)toErase.size(); ++i)
        optHi.erase(optHi.find(toErase[i]));
   
    cout << min << " " <<  (int) optLo.size() << endl;
    for(auto v : optHi)
       cout << get<1>(v)+1 << " ";
    for(auto v : optLo)
       cout << get<1>(v) + 1 << " ";
    cout << endl; 

}


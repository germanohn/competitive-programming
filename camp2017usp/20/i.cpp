#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair

typedef long long ll;

bool isPrime(ll n){
    if(n <= 1) return false;
    for(ll i = 2; i * i <= n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

ll clayton(ll x){
    if(x > 0) return x;
    return -x;
}

bool cmp(vector<ll> a, vector<ll> b){
    return ((int)a.size() <= (int) b.size());
}
int main(){
    ll a, b;
    cin >> a >> b;
    vector<ll> candA;
    vector<ll> candB;
    candA.pb(a);
    candB.pb(b);
    ll tmpA = a + 2;
    //while(isPrime(tmpA)){
    //    candA.pb(tmpA);
    //    tmpA += 2;
    //}
    if(isPrime(tmpA))
        candA.pb(tmpA); 
    tmpA = a - 2;
    if(isPrime(tmpA))
        candA.pb(tmpA);

    //while(isPrime(tmpA)){
    //    candA.pb(tmpA);
    //    tmpA -= 2;
    //}
    ll tmpB = b + 2;
    if(isPrime(tmpB))
       candB.pb(tmpB); 
   // while(isPrime(tmpB)){
   //     candB.pb(tmpB);
    //    tmpB +=2;
   // }
    tmpB = b-2;
    if(isPrime(tmpB))
       candB.pb(tmpB); 
 
    //while(isPrime(tmpB)){
    //    candB.pb(tmpB);
    //    tmpB -= 2;
   // }
    set<vector<ll> > caminhos;
    map<int, int> sz;
    for(auto ca : candA){
        for(auto cb : candB){
            vector<ll> p1;
            vector<ll> p2;
            bool direto = false;
            bool pelo2 = false;
            if(isPrime(clayton(ca - cb))){
                if(ca != a) p1.pb(ca);
                if(cb != b) p1.pb(cb);
                direto = true;
            }
            if(isPrime(clayton(ca-2)) && isPrime(clayton(cb-2)))
            {
                if(ca != a) p2.pb(ca);
                p2.pb(2);
                if(cb != b) p2.pb(cb);
                pelo2 = true;
            }
            if(direto){ 
                if(caminhos.find(p1) == caminhos.end()){
                    caminhos.insert(p1);
                    sz[(int)p1.size()]++;
                }
            }
            if(pelo2){ 
                if(caminhos.find(p1) == caminhos.end()){
                    caminhos.insert(p2);
                    sz[(int)p2.size()]++;
                }
            }
        }
    }
    if(caminhos.empty()){
        cout << "Unlucky Benny" << endl;
    }
    else{
        auto small = *(sz.begin());
        int szSmall = small.fi; 
        if(small.second >= 2)
        {
            cout << "Poor Benny" << endl;
            return 0;
        }
        auto it = *(caminhos.begin());
        while((int) it.size() != szSmall)
        {
            caminhos.erase(caminhos.begin());
            it = *(caminhos.begin());    
        }
        cout << a << "->" ;
        for(auto v : it)
            cout << v << "->";
        cout << b;
    }
}

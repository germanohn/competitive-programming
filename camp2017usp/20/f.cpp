#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair

typedef unsigned long long ll;

const int maxn = 1e5 + 1;
ll semana[maxn];
ll accuSum = 0;
ll n;
ll h;
bool f(ll sem)
{
    ll qntdBaixou = (1 + n*sem )*(n*sem)/2; 
    ll qntBaixouNoDia = n*sem + 1; // 
    ll alturaExpNoInicio = h - qntdBaixou; // meta no inicio
    ll alturaRealmente = 0 + (accuSum*sem);

    for(int i = 0; i < n; ++i)
    {
        alturaExpNoInicio -= qntBaixouNoDia++;
        alturaRealmente += semana[i];
        if(alturaExpNoInicio <= alturaRealmente) {
            return true;
        }
         
    }
    return false; 
}


int main()
{
    cin >> n >> h;
    for(int i = 0; i < n; ++i){
        cin >> semana[i];
        accuSum += semana[i];
    }
    ll lo = 0, hi = 1e9, mid;
    for(int i = 0; i < 200; ++i){
        mid = (hi+lo)/2;
        if(f(mid)){
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    ll achei = lo;
    ll diaInicial = n*achei + 1;
    ll qntdBaixou = (1+n*achei) * (n*achei)/2; 
    ll qntBaixouNoDia = n*achei + 1;
    ll alturaExpNoInicio = h - qntdBaixou;
    ll alturaRealmente = 0 + (accuSum * achei);
    for(int i = 0; i < n; ++i){
        alturaExpNoInicio -= qntBaixouNoDia++;
        alturaRealmente += semana[i];
        if(alturaExpNoInicio <= alturaRealmente) {
            cout << diaInicial + i << endl;
            return 0;
        }
    } 
}

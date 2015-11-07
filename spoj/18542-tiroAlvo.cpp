/* aprendido: pra comparar distancia, se compara elas ao quadrado
// nesse problema podia ser que a distancia procurada fosse menor que o 
// menor raio. entao era preciso
// nesse problema usava-se o lower bound*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100005;

int c, t;
ll r[MAX], d[MAX], a;

ll dis (ll x, ll y) {
    return x*x + y*y;
}

int main () {
    scanf ("%d %d", &c, &t);
    for (int i = 0; i < c; i++) {
        scanf ("%lld", &a);
        r[i] = a*a;
    }
    ll x, y;
    for (int i = 0; i < t; i++) {
        scanf ("%lld %lld", &x, &y);
        d[i] = dis (x, y);
    }
    ll ans = 0;
    
    for (int i = 0; i < t; i++) {
        ll ti = d[i];
        int e = 0, d = c-1, m;
        //coloquei d = m-1 pois estou interessado no lower bound
        while (d != e) {
            m = (e+d+1) / 2;
            if (r[m] > ti) d = m-1; 
            else
                e = m;
                
        }
        /* temos duas opcoes: o ti esta entre r[e] e r[d] (conta c-e-1)
        // o ti é menor ou igual a r[e] (conta c-e)*/
        if (ti > r[e]) ans += c-e-1;
        else ans += c-e;
    }
    printf ("%lld\n", ans);
}

#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const double inf = 1e18;

int n;
pair<double, double> v[N];

double len_pack(double t) {
    double _max = 0., _min = inf;
    for (int i = 0; i < n; i++) {
        double aux = (v[i].ff * (t - v[i].ss));
        if (aux < _min)
            _min = aux;
        if (aux > _max)
            _max = aux;
    }     
    return _max - _min;
}

int main() {
    while (scanf(" %d", &n)) {
        if (n == 0) 
            break;
        double tf = 0.;
        for (int i = 0; i < n; i++) {
            scanf(" %lf %lf", &v[i].ss, &v[i].ff);
            if (tf < v[i].ss)
                tf = v[i].ss;
        }

        int cont = 0;
        double lo = tf, hi = 1e9;
        while (cont < 150) {
            double m1 = lo + (hi - lo) / 3.;
            double m2 = lo + 2 * ((hi - lo) / 3.);

            if (len_pack(m1) < len_pack(m2)) 
                hi = m2;
            else 
                lo = m1;
            cont++;
        }

        printf("%lf\n", len_pack(lo));
    }
}


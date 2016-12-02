#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

const double eps = 1e-6;

double v[5];
double x[100005];
double y[100005];
double z[100005];
set<pdd> format;
map<pdd, multiset<pdd> > rock;
multiset<pdd>::iterator ite;

bool cmp(double a, double b) {
    return a > b;
}

int main() {
    int n, id, id1, id2;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %lf %lf %lf", &x[i], &y[i], &z[i]);
        v[0] = x[i], v[1] = y[i], v[2] = z[i];
        sort(v, v+3);
        pdd pd1;
        pdd pd2;
        pdd pd3;
        pd1 = make_pair(v[0], v[1]);
        pd2 = make_pair(v[0], v[2]);
        pd3 = make_pair(v[1], v[2]);
        format.insert(pd1);
        rock[pd1].insert(make_pair(v[2], i));

        //if (pd1 != pd2) {
        format.insert(pd2);
        rock[pd2].insert(make_pair(v[1], i));
        //}

        //if (pd1 != pd3 && pd2 != pd3) {
        format.insert(pd3);
        rock[pd3].insert(make_pair(v[0], i));
        //}
    }

    double ans1 = -1;
    double ans2 = -1;
    double aux;

    for (set<pdd>::iterator it = format.begin(); it != format.end(); it++) {
        //printf("Checando par %.0lf     %.0lf\n", it->first, it->second);
        if (rock[*it].size() <= 1) continue;
        pdd a, b;
        a = *(rock[*it].rbegin());
        ite = rock[*it].find(a);
        rock[*it].erase(ite);
        b = *(rock[*it].rbegin());
        //printf("Somando %.0lf com %.0lf\n", a.ff, b.ff);
        v[0] = a.ff + b.ff, v[1] = (*it).ff, v[2] = (*it).ss;
        aux = min(a.ff+b.ff, min((*it).ff, (*it).ss));
        aux = (double) aux / 2.0;
        //printf("    resposta = %lf\n", aux);
        if (aux > ans2 && a.ss != b.ss) {
            //printf("    atualizando com o par(%.0lf %.0lf) = %lf\n\n", a.ss+1, b.ss+1, aux);
            ans2 = aux;
            id1 = a.ss + 1;
            id2 = b.ss + 1;
        }
    }


    for (int i = 0; i < n; i++) {
        aux = min(x[i], min(y[i], z[i]));
        aux = (double)aux/2.0;
        if (aux > ans1) {
            ans1 = aux;
            id = i+1;
        }
    }

    if (ans1 >= ans2)
        printf("1\n%d\n", id);
    else
        printf("2\n%d %d\n", id1, id2);
    return 0;
}

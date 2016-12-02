#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

const double eps = 1e-6;
const int MAX = 100005;

double v[5], x[MAX], y[MAX], z[MAX];
set<pdd> format;
map<pdd, multiset<pdd> > rock;
multiset<pdd>::iterator ite;

bool cmp(double a, double b) {
    return a > b;
}

int main() {
    int n;
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %lf %lf %lf", &x[i], &y[i], &z[i]);
        v[0] = x[i], v[1] = y[i], v[2] = z[i];
        sort(v, v + 3, cmp);

        format.insert(pdd(v[0], v[1]));
        rock[pdd(v[0], v[1])].insert(pdd(v[2], i));
    }

    double ans1 = -1, ans2 = -1, aux;
    int id1, id2;
    for (set<pdd>::iterator it = format.begin(); it != format.end(); it++) {
        if (rock[*it].size() <= 1) continue;
        pdd a, b;
        a = *(rock[*it].rbegin());
        /*ite = rock[*it].find(a);
        rock[*it].erase(ite);
        b = *(rock[*it].rbegin());*/
        
        //rock[*it].erase(prev(rock[*it].end()), rock[*it].end());
        //b = *(rock[*it].rbegin()); 
        
        //v[0] = a.ff + b.ff, v[1] = (*it).ff, v[2] = (*it).ss;
        //sort(v, v + 3);

        aux = min(a.ff+b.ff, min((*it).ff, (*it).ss));     
        aux = (double) aux / 2.0;
        if (aux > ans2 && a.ss != b.ss) 
            ans2 = aux, id1 = a.ss + 1, id2 = b.ss + 1;
    }

    int id;
    for (int i = 0; i < n; i++) {
        aux = min(x[i], min(y[i], z[i]));
        aux = (double) aux / 2.0;
        if (aux > ans1) 
            ans1 = aux, id = i + 1;
    }

    //printf("ans1 %lf ans2 %lf\n", ans1, ans2);
    if (ans1 >= ans2) 
        printf("1\n%d\n", id);
    else 
        printf("2\n%d %d\n", id1, id2);
}

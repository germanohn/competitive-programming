#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

const double eps = 1e-6;

double v[5];
set<pdd> format;
map<pdd, multiset<pdd> > rock;

bool cmp(double a, double b) {
    return a > b;
}

int main() {
    int n;
    scanf(" %d", &n);

    for (double i = 0; i < n; i++) {
        scanf(" %d %d %d", &v[0], &v[1], &v[2]);
        sort(v, v + 3, cmp);

        format.insert(pdd(v[0], v[1]));
        rock[pdd(v[0], v[1])].insert(pdd(v[2], i));
    }

    double ans1 = -1, ans2 = -1;
    int id, id1, id2;
    for (set<pdd>::iterator it = format.begin(); it != format.end(); it++) {
        pdd a, b;
        a = (*(rock[*it].rbegin()));
        rock[*it].erase(prev(rock[*it].end()), rock[*it].end());
        if (rock[*it].size() != 0) {
            b = *(rock[*it].rbegin());
        } else {
            b = a;
        }
        
        if (a.ss != b.ss) v[0] = a.ff + b.ff;
        else v[0] = a.ff;
        v[1] = (*it).ff, v[2] = (*it).ss;
        sort(v, v + 3);
        double aux = (double) v[0] / 2.0;
        printf("ans1 %lf ans2 %lf\n", ans1, ans2);
        if (a.ss != b.ss && aux > ans2) {
            ans2 = aux;
            id1 = a.ss + 1, id2 = b.ss + 1;    
        } else if (a.ss == b.ss && aux > ans1) {
            ans1 = aux;
            id = a.ss + 1;
        }
    }


    if (ans2 > ans1) {
        printf("2\n%d %d\n", id1, id2);
    } else {
        printf("1\n%d\n", id);
    }
}

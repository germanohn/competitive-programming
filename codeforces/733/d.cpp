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

    for (int i = 0; i < n; i++) {
        scanf(" %lf %lf %lf", &v[0], &v[1], &v[2]);
        sort(v, v + 3, cmp);
        //prdoublef("i %d %d %d %d\n", i, v[0], v[1], v[2]);
        format.insert(pdd(v[0], v[1]));
        rock[pdd(v[0], v[1])].insert(pdd(v[2], i));
    }

    double ans = -1;
    int ans_a, ans_b;
    for (set<pdd>::iterator it = format.begin(); it != format.end(); it++) {
        pdd a, b;
        a = *(rock[*it].rbegin());
        rock[*it].erase(*(rock[*it].rbegin()));
        if (rock[*it].size() != 0) {
            b = *(rock[*it].rbegin());
        } else {
            b = a;
        }
        
        v[0] = a.ff + b.ff, v[1] = (*it).ff, v[2] = (*it).ss;
        sort(v, v + 3);
        double aux = (double) v[0] / 2.0;
        if (aux > ans + eps) {
            ans = aux;
            if (a.ss != b.ss)
                ans_a = a.ss, ans_b = b.ss;
            else 
                ans_a = ans_b = a.ss;
        }
    }

    if (ans_a != ans_b) {
        printf("2\n%d %d\n", ans_a + 1, ans_b + 1);
    } else {
        printf("1\n%d\n", ans_a + 1);
    }
}

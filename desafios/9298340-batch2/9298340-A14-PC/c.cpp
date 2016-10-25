#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double inf = 1e9;
const double eps = 1e-8;

int p[5][5], ans[5];
double v[5], best = -inf;

double calc (int kind) {
    int a, b, c;
    a = p[kind][0], b = p[kind][1], c = p[kind][2];
    if (v[a] <= 1 + eps && v[b] <= 1 + eps && v[c] <= 1 + eps) { 
        if (kind == 0) {
            return pow (v[a], pow (v[b], v[c]));
        } else {
            return pow (pow (v[a], v[b]), v[c]);
        }
    }

    if (v[a] <= 1 + eps) 
        return -inf;

    double ret;
    if (kind == 0) {
        ret = v[c] * log (v[b]) + log (log (v[a]));
    } else {
        ret = log (v[c]) + log (v[b] * log (v[a]));
    }

    return ret;
}

void solve (int i) {
    double tmp;
    tmp = calc (i);
    if (tmp - best > eps) 
        best = tmp, ans[0] = i, ans[1] = p[i][0], ans[2] = p[i][1], ans[3] = p[i][2];
}

char rename (int i) {
    if (i == 0) {
        return 'x';    
    } else if (i == 1) {
        return 'y';
    } else {
        return 'z';
    }
}

int main () {
    scanf (" %lf %lf %lf", &v[0], &v[1], &v[2]);
    p[0][0] = 0, p[0][1] = 1, p[0][2] = 2;

    for (int i = 0; i < 12; i += 4) {
        if (i != 0) 
            next_permutation (p[0], p[0]+3);
        p[1][0] = p[0][0], p[1][1] = p[0][1], p[1][2] = p[0][2];
        solve (0);
        next_permutation (p[0], p[0]+3);
        solve (0);

        solve (1);
        next_permutation (p[1], p[1]+3);
        solve (1);
    }

    if (ans[0] == 0) {
        printf ("%c^%c^%c\n", rename (ans[1]), rename (ans[2]), rename (ans[3]));
    } else {
        printf ("(%c^%c)^%c\n", rename (ans[1]), rename (ans[2]), rename (ans[3]));
    }
}


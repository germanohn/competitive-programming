#include <bits/stdc++.h>

using namespace std;

struct tipo {
    long long int norma, x, y;
};

tipo pto[1005], now, ori[1005];

long long int tmp;
int n, ans;

bool comp (tipo a, tipo b) {
    long long int na, nb;
    na = a.norma, nb = b.norma;
    return na < nb;
}

int comb (int num) {
    return num * (num-1)/2;
}

int main () {
    while (scanf ("%d", &n) && n != 0) {
        ans = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%lld %lld", &pto[i].x, &pto[i].y);
            ori[i] = pto[i];
        }
        for (int i = 0; i < n; i++) {
            now = pto[i];
            pto[i] = pto[n-1];
            pto[n-1] = now;
            for (int j = 0; j < n-1; j++) {
                pto[j].norma = (pto[j].x - now.x)*(pto[j].x - now.x) + (pto[j].y - now.y)*(pto[j].y - now.y); 
            }
            sort (pto, pto + n-1, comp);
            int quant = 0;
            tmp = pto[0].norma;
            for (int j = 0; j < n-1; j++) {
                if (pto[j].norma != tmp) {
                    ans += comb (quant);
                    quant = 0;
                    tmp = pto[j].norma;
                }
                quant++;
            }
            ans += comb (quant);
            for (int j = 0; j < n; j++) {
                pto[j] = ori[j];
            }
        }
        printf ("%d\n", ans);
    }
}

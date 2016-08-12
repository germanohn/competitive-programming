#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize


int main () {
    int a, b;
    scanf ("%d %d", &a, &b);
    int n;
    scanf ("%d", &n);
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        double x, y, v;
        scanf ("%lf %lf %lf", &x, &y, &v);
        double dis = ((x-a)*(x-a) + (y-b)*(y-b));
        dis = sqrt (dis);
        dis /= v;
        ans = min (ans, dis);
    }
    printf ("%lf\n", ans);
}


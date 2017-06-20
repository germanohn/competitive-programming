#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 105;
const double eps = 1e-9;

int n;
double k;
double a[N];

int main () {
    scanf(" %d %lf", &n, &k);
    double sum = 0.;
    for (int i = 0; i < n; i++) {
        scanf(" %lf", &a[i]);
        sum += a[i];
    }

    int cont = 0;
    while (k - ((sum + double(cont) * k) / (n + cont)) > double(0.5) - eps) {
        cont++;
    }
    if (cont) cont--;

    printf("%d\n", cont);

}


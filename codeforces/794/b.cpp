#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-9; 

double n, h;

double area(double x) {
    return (x * x) / (2. * h);
}

int main () {
    scanf(" %lf %lf", &n, &h);
    
    double ini = h / (2. * n);
    for (int i = 0; i < n - 1; i++) {
        double aux = ini * double(i + 1);

        int cont = 0;
        double lo = 0, hi = h;
        while (cont < 150) {
            double mid = (lo + hi) / 2.;
            if (area(mid) < aux + eps) 
                lo = mid;
            else 
                hi = mid;
            cont++;
        }
        printf("%.8lf ", lo);
    }
    printf("\n");
}


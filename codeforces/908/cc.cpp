#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;

int n;
ll r;
ll x[N];
double y[N];

int main() {
    scanf(" %d %lld", &n, &r);
    for (int i = 0; i < n; i++)
        scanf(" %lld", &x[i]);

    for (int i = 0; i < n; i++) {
        y[i] = r;
        for (int j = 0; j < i; j++) {
            ll d = abs(x[i] - x[j]);
            if (d <= 2 * r)
                y[i] = max(y[i], sqrt(4 * r * r - d * d));
        }
        printf("%.8lf ", y[i]);
    }
}


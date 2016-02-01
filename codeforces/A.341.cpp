#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll par, im, v[100005];
int n, a;

int main () {
    scanf ("%d", &n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        if (a % 2 == 0) par += a;
        else v[k] = a, k++, im += a;
    }
    sort (v, v+k);
    if (k % 2 == 0) cout << par+im << endl;
    else {
        im -= v[0];
        cout << par+im << endl;
    }
}

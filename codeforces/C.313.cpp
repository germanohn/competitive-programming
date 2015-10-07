#include <bits/stdc++.h>

using namespace std;

int v[6];

int main () {
    for (int i = 0; i < 6; i++) {
        scanf ("%d", &v[i]);
    }
    long long int tot = pow (v[0] + v[1] + v[5], 2);
    tot -= (v[5] * v[5]) + (v[1] * v[1]) + (v[3] * v[3]);
    cout << tot << endl; 

}

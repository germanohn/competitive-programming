#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main () {
    scanf(" %d", &n);
    double percentage = 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf(" %d", &val);
        percentage += val;
    }

    percentage /= (double) (n * 100);
    printf("%lf\n", 100 * percentage);
}


#include <bits/stdc++.h>

using namespace std;

long long int d, ans, n;

int main () {
    cin >> n;
    d = 2, ans = 1;
    while (n > 1 && (d * d) <= n) {
        if (n % d == 0) {
            ans *= d;
            while (n % d == 0)  
                n /= d;
        }
        d++;
    }
    ans *= n;
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int n, sum, ans, v[10005];
int main () {
    while (scanf ("%d", &n) != EOF) {
        sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
            sum += v[i];
        }
        if (sum % n == 0) {
            sum = sum/n;
            for (int i = 0; i < n; i++) {
                ans += abs (v[i] - sum);
            }
            printf ("%d\n", ans/2 + 1);
        }   
        else printf ("-1\n");
    }
}

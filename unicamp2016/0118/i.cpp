#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main () {
    int acc[2000], a, b, n;
    memset (acc, 0, sizeof acc);
    scanf ("%d", &n);
    acc[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &a, &b);
        for (int j = a; j <= b; j++)
            acc[j] = 1;
    }
    for (int i = 1; i <= 1826; i++) acc[i] += acc[i-1];
    for (int i = 180; i <= 1826; i++) {
        if (acc[i]-acc[i-180] > 90) {
            printf ("No\n");
            return 0;
        }
    }
    printf ("Yes\n");
}

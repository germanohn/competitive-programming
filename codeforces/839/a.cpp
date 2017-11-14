#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);

    int acc = 0, has = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);

        acc += a;
        int give = min(8, acc);
        acc -= give;
        has += give;

        if (has >= k) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("-1\n");
}


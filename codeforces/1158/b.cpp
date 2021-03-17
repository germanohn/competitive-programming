#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);

    int len_pattern = (n - k) / 2 + 1;
    for (int i = 1; i <= n; i++) {
        if (i % len_pattern) {
            printf("0");
        } else {
            printf("1");
        }
    }
    printf("\n");
}

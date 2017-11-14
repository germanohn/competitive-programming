#include<bits/stdc++.h>
using namespace std;

const int N = 1500;

int n;

int main() {
    scanf(" %d", &n);
    int maxi = -1;
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        if (a < maxi) {
            printf("no\n");
            return 0;
        }
        maxi = max(maxi, a);
    }

    printf("yes\n");
}


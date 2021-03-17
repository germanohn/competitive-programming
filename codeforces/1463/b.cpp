#include<bits/stdc++.h>
using namespace std;

#define N 55
#define MAX 1e9

int a[N], b[N];

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n;
        scanf(" %d", &n);
        
        for (int i = 0; i < n; i++) {
            scanf(" %d", &a[i]);
        } 

        for (int i = 0; i < n; i++) {
            int powertwo = 0;
            for (; (1 << (powertwo + 1)) <= a[i]; powertwo++);

            printf("%d ", 1 << powertwo);
        }
        printf("\n");
    }
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int v[105];

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        v[a] = i + 1;
    }

    for (int i = 1; i <= n; i++) 
        printf("%d ", v[i]);
    printf("\n");
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n, x, acc = 0;

    scanf(" %d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        acc += (a);
    }

    printf("%d\n", (abs(acc) + x - 1) / x);
}


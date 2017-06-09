#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    scanf(" %d", &n);
    if (n == 0) {
        printf("1\n");
    } else if (n == 1) {
        printf("8\n");
    } else {
        int v[4] = {4, 2, 6, 8};
        n -= 2;
        n %= 4;
        printf("%d\n", v[n]);
    }
}


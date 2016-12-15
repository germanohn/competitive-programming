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
    if (n > 0) printf("%d\n", n);
    else {
        int a, b;
        a = -n % 10, n /= 10;
        b = -n % 10, n /= 10;
        if (a > b) swap(a, b);
        if (n != 0) printf("%d%d\n", n, a);
        else if (a != 0) printf("-%d\n", a);
        else printf("0\n");
    }
}


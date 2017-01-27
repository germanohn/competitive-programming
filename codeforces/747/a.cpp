#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int n;
    scanf(" %d" , &n);
    int a, b;
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;
        if (n / i < i) break;
        a = i, b = n / a;
    }
    printf("%d %d\n", a, b);
}


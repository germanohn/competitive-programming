#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int k, a, b;

int main () {
    scanf(" %d %d %d", &k, &a, &b);
    if (a < b) swap(a, b);

    if ((a % k != 0 && b < k) || a < k) printf("-1\n");
    else 
        printf("%d\n", a/k + b/k);
}


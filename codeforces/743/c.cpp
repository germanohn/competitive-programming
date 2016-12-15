#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main () {
    scanf(" %d", &n);
    if (n == 1) printf("-1\n");
    else printf("%d %d %d\n", n, n + 1, n * (n + 1));
}


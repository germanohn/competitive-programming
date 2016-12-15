#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    int y, k, n;
    scanf(" %d %d %d", &y, &k, &n);
    int a;
    for (a = k; a <= n; a += k) 
        if (a > y)
            break;
    int cont = 0;
    for (int i = a; i <= n; i += k) 
        printf("%d ", i - y), cont++;
    if (cont) printf("\n");
    else printf("-1\n");
}


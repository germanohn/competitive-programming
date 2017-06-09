#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;

int main () {
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        if (i <= k) printf("%d ", k + 1 - i);
        else printf("%d ", i + 1);
    }
    printf("\n");
}


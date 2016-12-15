#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, k;

int main () {
    scanf(" %lld %lld", &n, &k);
    if (k % 2 == 1) {
        printf("1\n");
    } else {
        ll st = 2, r = 4;
        for (int i = 2; i <= n; i++) {
            ll aux = k - st;
            if (aux % r == 0) {
                printf("%d\n", i);
                return 0;
            }
            st *= 2, r *= 2;
        }
    }
}


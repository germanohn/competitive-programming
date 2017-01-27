#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n;

int main () {
    scanf(" %lld", &n);
    if (n <= 2) printf("%d\n", n);
    else {
        if (n % 2 == 1) 
            printf("%lld\n", n * (n - 1) * (n - 2));
        else {
            if (n % 3 == 0) 
                printf("%lld\n", (n - 1) * (n - 2) * (n - 3));
            else 
                printf("%lld\n", n * (n - 1) * (n - 3));
        }
    }
}


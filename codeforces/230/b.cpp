#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int n;
int p[MAX];

void sieve() {
    p[1] = true;
    for (ll i = 2; i < MAX; i++) 
        if (!p[i]) 
            for (ll j = i * i; j < MAX; j += i) 
                p[j] = true;
}

int main () {
    sieve();
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        scanf(" %lld", &a);
        b = sqrt(a);
        if (b * b == a && !p[b]) printf("YES\n");
        else printf("NO\n");
    }
}


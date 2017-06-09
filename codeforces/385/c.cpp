#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e7 + 5;

int n, m;
int p[N];
ll pre[N];

void sieve() {
    for (ll i = 2; i < N; i++) {
        if (!p[i]) {
            for (ll j = i; j < N; j += i) 
                p[j] = i;
        }
    }
}

int main () {
    sieve();
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        while (a > 1) {
            int d = p[a];
            pre[p[a]]++;
            while (p[a] == d) 
                a /= p[a];
        }
    }

    for (int i = 1; i < N; i++) 
        pre[i] += pre[i - 1];


    scanf(" %d", &m);
    while (m--) {
        int l, r;
        scanf(" %d %d", &l, &r);
        l = min(l, N - 5);
        r = min(r, N - 5);
        printf("%lld\n", pre[r] - pre[l - 1]);
    }
}


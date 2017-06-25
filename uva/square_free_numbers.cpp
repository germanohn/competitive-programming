#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int t, n;
int p[N];

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!p[i]) {
            for (int j = i; j < N; j += i)
                p[j] = i;
        }
    }
}

int main() {
    sieve();
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
    
        //int o = n;
        int ans = 0;
        while (n > 1) {
            int d = p[n];
            int cont = 0;
            while (n > 1 && d == p[n]) {
                n /= p[n];
                cont++;
            }
            
            if (cont > ans) 
                ans += (cont - ans);
        }
        printf("%d\n", ans);
    }
}

#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
ll x;

int main () {
    cin >> n >> x;
    int ans = 0, qtd;
    char sinal;
    for (int i = 0; i < n; i++) {
        scanf (" %c %d", &sinal, &qtd);
        if (sinal == '-') {
            if (x - qtd >= 0) {
                x -= (ll) qtd;
            } else {
                ans++;
            }
        } else {
            x += (ll) qtd;
        
        }
    }
    cout << x << ' ' << ans << '\n';
}


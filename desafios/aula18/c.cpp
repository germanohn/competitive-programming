#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n, k, s;

int dp (int i, int mask) {
    int sum = 0;
    for (int i = 0; i < 20; i++) {
        if ((i & mask) != 0) 
            sum += i+1;
    }

    if (i == k) {
        if (sum == s) return 1;
        else return 0;
    }
    if (me[qtd][sum] != -1) return me[qtd][sum];

    for (int i = 0; i < 20; i++) {
        if ((i & mask) != 0) {
            
        }
    }

    return me[qtd][sum] = ans;
}

int main() {
    while (scanf ("%d %d %d", &n, &k, &s)) {
        if (n == 0 && k == 0 && s == 0) break;

        int val = 0;
        for (int i = n; i > 0; i--) {
            int a = 0;
            if (val >= i) 
                a = i;

            val = val*10 + 
        }
        dp (k, s);
    }
}


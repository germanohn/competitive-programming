#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

int n;
int v[N], p[N];

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        pa[i] = v[i] % 2;
    }

    bool ok = true;
    int d = gcd(v[0], v[1]);
    for (int i = 2; i < n; i++) {
        d = gcd(d, v[i]);
        if (d == 1) {
            ok = false;
            break;
        }
    }

    printf("YES\n");
    if (d != 1 && ok) { 
        printf("0\n");
    } else {
        int ans = 0;
        bool f = false;
        for (int i = 0; i < n-1; i++) {
            if (p[i] == 1) {
                if (p[i + 1] == 1) {
                    
                }
            }
        }
        printf("%d\n", ans);
    }
}


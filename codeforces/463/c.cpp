#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2005;

int n;
int t[MAX][MAX];
ll d1[2 * MAX], d2[2 * MAX];
tuple<ll, int, int> bishop1, bishop2;

int main () {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %d", &t[i][j]);
            d2[i + j] += (ll) t[i][j];
            d1[(i - j) + n - 1] += (ll) t[i][j];
        }
    }
    get<1>(bishop1) = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll aux = d2[i + j] + d1[i - j + n - 1] - (ll) t[i][j];
            if ((i + j) % 2 == 0 && aux > get<0>(bishop1)) 
                bishop1 = make_tuple(aux, i, j);
            else if ((i + j) % 2 == 1 && aux > get<0>(bishop2))
                bishop2 = make_tuple(aux, i, j);
        }
    }
    ll b1, b2;
    int a, b, c, d;
    tie(b1, a, b) = bishop1;
    tie(b2, c, d) = bishop2;
    printf("%lld\n%d %d %d %d\n", b1 + b2, a + 1, b + 1, c + 1, d + 1);
}


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

int a[3];
int b[3];

int main() {
    scanf (" %d %d %d", a, a+1, a+2);
    scanf (" %d %d %d", b, b+1, b+2);
    sort (a, a+3);
    sort (b, b+3);
    bool can = true;
    if (a[0]*a[0] + a[1]*a[1] != a[2]*a[2]) can = false;
    if (b[0]*b[0] + b[1]*b[1] != b[2]*b[2]) can = false;
    for (int i = 0; i < 3; i++)
        if (a[i] != b[i]) can = false;
    printf("%s\n", can ? "YES" : "NO");
}


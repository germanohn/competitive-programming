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
typedef pair<int, double> pid;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAX = 35;
const int modn = 1000000007;

int n, m, k, arbritage;
double d[MAX][MAX];
map<string, int> coin;

void floyd () {

    for (int l = 0; l < n; l++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) { 
                d[i][j] = max (d[i][j], d[i][l] * d[l][j]);
            }
}

int main() {
    int cont = 1;
    while (scanf (" %d", &n)) {
        if (n == 0) break;
        coin.clear ();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                d[i][j] = 0.0;
        arbritage = false;

        char s1[20], s2[20];

        for (int i = 0; i < n; i++) {
            scanf (" %s", s1);
            string s = s1;
            coin[s] = i; 
        }

        double fee;
        scanf (" %d", &m);
        for (int i = 0; i < m; i++) {
            scanf (" %s %lf %s", s1, &fee, s2);
            string a = s1, b = s2;
            d[coin[a]][coin[b]] = fee;
        }

        floyd ();

        for (int i = 0; i < n; i++) {
            if (d[i][i] > 1.) arbritage = true;
        }

        if (arbritage) {
            printf ("Case %d: Yes\n", cont++);
        } else {
            printf ("Case %d: No\n", cont++);
        }
    }
}


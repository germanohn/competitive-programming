#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000007;
inline ll mod (ll x) { return x % modn; }

int ans[505][505];
int num[250005];

int main () {
    int n, k, sum = 0;
    scanf ("%d %d", &n, &k);
    int aux = n*n;
    for (int i = 0; i < n*n; i++) 
        num[i] = aux, aux--;
    int f = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = n; j >= k; j--) {
            if (j == k) sum += num[f];
            ans[i][j] = num[f++];
        }
    for (int i = 1; i <= n; i++) 
        for (int j = k-1; j >= 1; j--) 
            ans[i][j] = num[f++];
    printf ("%d\n", sum);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf ("%d ", ans[i][j]);
        printf ("\n");
    }
}

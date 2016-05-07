#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int pos[100005];

int main () {
    scanf ("%d", &n);
    int a;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        pos[a] = i;
    }
    int ans = 1, tmp = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i-1] < pos[i]) {
            tmp++;
        } else {
            ans = max (ans, tmp);
            tmp = 1;
        }
        ans = max (ans, tmp);
    }
    printf ("%d\n", n-ans);
}

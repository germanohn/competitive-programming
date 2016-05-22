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

int main () {
    scanf ("%d", &n);
    int prev = 0, cur;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &cur);
        if (cur - prev > 15) {
            break;
        } else {
            prev = cur;
        }
    }
    cout << min (prev + 15, 90) << "\n";
}

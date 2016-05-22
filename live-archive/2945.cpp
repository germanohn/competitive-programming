#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000005;

int n, k;
int v[MAX];
set<pii> ship;

int main () {
    while (scanf ("%d", &k) != EOF) {
        scanf ("%d", &n);
        int cont = 0, a, b, quant = 0;
        while (quant < n) {
            char str[20];
            gets (str);
            if (str[0] == 'b') {
                sscanf (str, "b %d %d", &a, &b);
                for (int j = 0; j < a; j++) 
                    v[cont++] = b;
                quant += a;
            } else {
                scanf ("%d", &a);
                v[cont++] = a;
                quant++;
            }
        }
        for (int i = 0; i < cont; i++) 
            printf ("%d ", v[i]);
        printf ("\n");
        printf ("oi\n");
        int sum = 0, ans = 1;
        set<pii>::iterator it;
        for (int i = 0; i < cont; i++) {
            if (sum + v[i] > k) {
                ans++;
                it = ship.lower_bound (pii (0, 0));
                ship.insert (pii (sum, i));
                printf ("bah\n");
                sum = 0;
                if ((*it).ff + v[i] <= k) {
                    int val = (*it).ff + v[i];
                    ship.erase (it);
                    ship.insert (pii (val, i));
                } else {
                    ship.insert (pii (v[i], i));
                }
            } else {
                sum += v[i];    
            }
        }
        printf ("%d\n", ans);
    }
}


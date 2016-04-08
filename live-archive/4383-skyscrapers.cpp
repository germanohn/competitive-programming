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

int t, n, d;
int h[MAX];

int main () {
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &d);
        for (int i = 0; i < n; i++) 
            scanf ("%d", &h[i]);
        bool in = false;
        int cont, level;
        for (int i = 0; i < d; i++) {
            scanf ("%d", &level);
            cont = 0;
            for (int j = 0; j < n; j++) {
                // Casos:
                // altura menor ou igual ao level e venho de uma nao regiao:
                if (h[j] <= level && !in) {
                    in = true;
                    cont++;
                // altura maior ou igual ao level e venho de uma regiao
                } else if (h[j] > level && in) {
                    in = false;
                }
            }
            printf ("%d ", cont);
        }
    }
}


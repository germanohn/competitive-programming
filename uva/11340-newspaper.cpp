#include <bits/stdc++.h>
#include <wchar.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000;

int n, k, m;
ll v[MAX];
char line[112345];

int main () {
    scanf ("%d", &n);
    while (n--) {
        for (int i = 0; i < MAX; i++) 
            v[i] = 0;
        scanf ("%d", &k);
        getchar ();
        char c[100];
        ll cost;
        for (int i = 0; i < k; i++) {
            fgets (c, 100, stdin);
            cost = atoi (c+2);
            int num = c[0]+400;
            v[num] = cost;
        }
        scanf ("%d", &m);
        getchar ();
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            fgets (line, 10005, stdin);
            for (int j = 0; line[j] != '\0'; j++) {
                int num = line[j]+400;
                ans += v[num];
            }  
        }
        printf ("%.2lf$\n", 0.01*ans);
    }
}

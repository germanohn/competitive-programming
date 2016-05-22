#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int con, prob, tempo, status, t, c;

int main () {
    scanf ("%d", &t);
    while (t--) {
        getchar ();
        while (c = getchar () && c != '\n') {
            printf ("c %d\n", c);
            con = c + '0';
            scanf ("%d %d %d", &prob, &tempo, &status);
            printf ("oi\n");
            getchar ();
        }
        printf ("con %d prob %d tempo %d status %d\n", con, prob, tempo, status);
    }
}


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
char str[100005];
set<char> s;

int main () {
    scanf ("%d", &n);
    scanf (" %s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        s.insert (str[i]);
    }
    if (strlen (str) > 26) {
        printf ("-1\n");
    } else {
        int ans = strlen (str) - s.size ();
        printf ("%d\n", ans);
    }
}


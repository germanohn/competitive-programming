#include <bits/stdc++.h>
#include <string>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
string s;

int main () {
    scanf ("%d", &n);
    for (int i = 1; s.size () <= 1005; i++) {
        s = s + to_string (i);
    }
    printf ("%c\n", s[n-1]);
}

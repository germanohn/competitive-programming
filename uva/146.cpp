#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string s;

int main () {
    while (cin >> s && s[0] != '#') {
        if (next_permutation (s.begin (), s.end ())) {
            cout << s << "\n";        
        } else {
            printf ("No Successor\n");
        }
    }
}


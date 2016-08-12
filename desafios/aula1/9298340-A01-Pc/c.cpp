#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

bool seen[105];

int main() {
    int n;
    char s[105];
    scanf ("%d", &n);
    scanf (" %s", s);
    for (int i = 0; s[i] != 0; i++) {
        char c = tolower (s[i]);
        seen[c-'a'] = true;
    }
    bool f = true;
    for (int i = 0; f && i < 26; i++) {
        if (!seen[i]) f = false;
    }
    if (f) printf ("YES\n");
    else printf ("NO\n");
}


#include <bits/stdc++.h>
#define ff first
#define ss second 
#define pb push_back
#define mp make_pair
#define debug(args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variáveis dadas no exercício, nao as reutilize

const int MAX = 100005;

char s[MAX];
int z[MAX], freq[MAX], acc[MAX];
vector<pii> ans;

void z_function () {
    int l = -1, r = -1;
    int n = strlen (s);
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r] == s[r-l]) r++;
            z[i] = r-l, r--;
        } else {
            int k = i-l;
            if (z[k] < r-i+1) z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r] == s[r-l]) r++;
                z[i] = r-l, r--;
            }
        }
    }
}

int main () {
    scanf (" %s", s);
    int n = strlen (s);
    z_function ();
    z[0] = n;
    for (int i = 0; i < n; i++) 
        freq[z[i]]++;
    for (int i = n; i >= 0; i--)
        acc[i] += acc[i+1]+freq[i];
    for (int i = 1; i < n; i++) {
        if (z[i] + i == n) 
            ans.pb (pii (z[i], acc[z[i]]));
    }
    ans.pb (pii (z[0], 1));
    sort (ans.begin (), ans.end ());
    printf ("%d\n", ans.size ());
    for (int i = 0; i < ans.size (); i++) 
        printf ("%d %d\n", ans[i].ff, ans[i].ss);
}

#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 5;
const int inf = 1e6;

int n, ans;
int pos[150];
char house[MAX];
set<char> types;

int main () {
    scanf ("%d", &n);
    scanf (" %s", house);
    memset (pos, -1, sizeof pos);
    for (int i = 0; house[i] != 0; i++) 
        types.insert (house[i]);
    int qtd = types.size ();
    int ans = inf, tmp = 0, l = 0;
    for (int i = 0; house[i] != 0; i++) {
        if (pos[house[i]] == -1) {
            tmp++;
            pos[house[i]] = i;
        } else {
            pos[house[i]] = i;
            while (pos[house[l]] != l) 
                l++;
        }
        if (tmp == qtd && i-l+1 < ans) 
            ans = i-l+1;

    }
    printf ("%d\n", ans);
}


#include<bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n, m, grupo[30];
char s[MAX];
vector<int> v[30];

int main () {
    scanf ("%d %d", &n, &m);
    scanf (" %s", s);
    for (int i = 0; i < 26; i++) 
        grupo[i] = -1;
    int k = 0;
    for (int i = 0; s[i] != 0; i++) {
        int l = s[i]-'a';
        if (grupo[l] == -1) {
            grupo[l] = k;
            v[k].pb (i);
            k++;
        } else {
            v[grupo[l]].pb (i);
        }
    }
    char x, y;
    for (int i = 0; i < m; i++) {
        scanf (" %c %c", &x, &y);
        int tmp = grupo[x-'a'];
        grupo[x-'a'] = grupo[y-'a'];
        grupo[y-'a'] = tmp;
    }
    for (int i = 0; i < 26; i++) {
        if (grupo[i] != -1) {
            for (int j = 0; j < v[grupo[i]].size (); j++) {
                int pos = v[grupo[i]][j];
                s[pos] = i+'a';
            }
        }
    }
    printf ("%s\n", s);
}

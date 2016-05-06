#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 200005;

int n, m, a, b;
int f[MAX], l[5][MAX];
map<int, int> mp;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < MAX; i++) {
        f[i] = 0;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a);
        if (mp.find (a) == mp.end ()) {
            mp[a] = k++;
        }
        a = mp[a];
        f[a]++;
    }
    // tenho um vetor com a quantidade de cientistas que gostam da lingua i
    scanf ("%d", &m);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            scanf ("%d", &l[i][j]);
            l[i][j] = mp[l[i][j]];
        }
    }
    int audio = -1, sub = -1, ans = 0;
    for (int i = 0; i < m; i++) {
        a = l[0][i], b = l[1][i];
        if (f[a] > audio || (f[a] == audio && f[b] > sub)) {
            ans = i+1;
            audio = f[a], sub = f[b];
        }    
    }
    printf ("%d\n", ans);
}


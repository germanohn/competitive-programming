#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 105;

int n, degree[30], ans[30];
char name[MAX][MAX];
vector<int> adj[30];
queue<int> q;
bool f;

bool solve () {
    for (int i = 0; i < n-1; i++) {
        int a = strlen (name[i]), b = strlen (name[i+1]), j;
        for (j = 0; j < min (a, b); j++) {
            int u = name[i][j]-'a', v = name[i+1][j]-'a';
            if (u != v) {
                adj[u].pb (v);
                degree[v]++;
                break;
            }
        }
        if (j == min (a, b) & a > b) 
            f = true;
    }    
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf (" %s", name[i]);
    solve ();
    // toposort
    for (int i = 0; i < 26; i++) 
        if (degree[i] == 0)
            q.push (i);
    int k = 0;
    while (!q.empty ()) {
        int x = q.front ();
        q.pop ();
        ans[k++] = x;
        for (int i = 0; i < adj[x].size (); i++) {
            int y = adj[x][i];
            degree[y]--;
            if (degree[y] == 0)
                q.push (y);    
        }
    }
    for (int i = 0; i < 26; i++) {
        if (degree[i] != 0) 
            f = true;
    }
    if (f) printf ("Impossible\n");
    else {
        for (int i = 0; i < 26; i++) 
            printf ("%c", ans[i]+'a');
        printf ("\n");
    }
}










#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

int n;
int len[MAX], vis[MAX];
char dir[MAX];

int main () {
    scanf ("%d", &n);
    getchar ();
    for (int i = 0; i < n; i++) {
        scanf ("%c", &dir[i]);
    }
    for (int i = 0; i < n; i++) 
        scanf ("%d", &len[i]);
    
    int pos = 0;
    bool f = true;
    for (int i = 0; f && i < n; i++) {
        if (dir[pos] == '>') {
            pos += len[pos];
            if (pos >= n)
                f = false;
        } else {
            pos -= len[pos];
            if (pos < 0)
                f = false;
        }
    } 
    if (!f)
        printf ("FINITE\n");
    else 
        printf ("INFINITE\n");
}


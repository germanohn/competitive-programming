#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 10005;

int tam;
char s1[MAX], s2[MAX];
set<string> pal;

int main () {
    scanf (" %s", s1);
    tam = strlen (s1);
    for (int i = 5; i < tam; i++) {
        if (i + 1 < tam && tam - (i+2) != 1) {
            strncpy (s2, s1 + i, 2);
            // tem que ser diferente da pal antes e da pal depois
            if (s2[0] == s1[i-2] && s2[1] == s1[i-1]) 
                continue;
            if (s2[0] == s1[i+2] && s2[1] == s1[i+3]) 
                continue;
            s2[2] = '\0';
            pal.insert (s2);
        } 
        if (i + 2 < tam && tam - (i+3) != 1) {
            strncpy (s2, s1 + i, 3);
            // antes
            if (s2[0] == s1[i-3] && s2[1] == s1[i-2] && s2[2] == s1[i-1])
                continue;
            if (s2[0] == s1[i+3] && s2[1] == s1[i+4] && s2[2] == s1[i+5])
                continue;
            s2[3] = '\0';
            pal.insert (s2);
        } 
    } 
    tam = pal.size ();
    printf ("%d\n", tam);
    set<string>::iterator it;
    for (it = pal.begin (); it != pal.end (); it++) {
        cout << (*it) << "\n";
    }
}


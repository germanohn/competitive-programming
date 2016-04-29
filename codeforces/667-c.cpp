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

char s1[MAX], s2[MAX];
int me[MAX][2];
set<string> pal;

void dp (int i, int ant) {
    if (i <= 4) 
        return;
    if (me[i][ant] != -1) return; 
    me[i][ant] = 1;
    if (ant == 2) {
        if (s1[i] != s1[i+2] && s1[i-1] != s1[i+1]) {
            s2[0] = s1[i-1], s2[1] = s1[i], s2[2] = '\0';
            pal.insert (s2);
            dp (i-2, 2);
        }
        s2[0] = s1[i-2], s2[1] = s1[i-1], s2[2] = s1[i-2], s2[3] = '\0';        
        pal.insert (s2);
        dp (i-3, 3);
    } else {
        if (s1[i] != s1[i+3] && s1[i-1] != s1[i+2] && s2[i-2] != s1[i+3]) {
            s2[0] = s1[i-2], s2[1] = s1[i-1], s2[2] = s1[i-2], s2[3] = '\0';        
            pal.insert (s2);
            dp (i-3, 3);
        }
        s2[0] = s1[i-2], s2[1] = s1[i-1], s2[2] = s1[i-2], s2[3] = '\0';        
        pal.insert (s2);
        dp (i-2, 2);
    }
}

int main () {
    scanf (" %s", s1);
    int tam = s1.length ();
    if (tam - 3 >= 5) {
        s2[0] = s1[tam-2], s2[1] = s1[tam-1], s2[2] = '\0';
        dp (tam - 3, 2);
        pal.insert (s2);
    }
    if (tam - 4 >= 5) {
        s2[0] = s1[tam-3], s2[1] = s1[tam-2], s2[2] = s1[tam-3], s2[3] = '\0';        
        dp (tam - 4, 3);
        pal.insert (s2);   
    }
    tam = pal.size ();
    printf ("%d\n", tam);
    set<string>::iterator it;
    for (it = pal.begin (); it != pal.end (); it++) {
        printf ("%s\n", (*it));
    }
}









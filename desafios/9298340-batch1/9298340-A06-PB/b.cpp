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

const int MAX = 10005;

int n, l, r, k;
char s[MAX], aux[MAX];

int main () {
    scanf (" %s %d", s, &n);
    for (int j = 0; j < n; j++) {
        scanf ("%d %d %d", &l, &r, &k);
        l--, r--;
        /*for (int i = l; i <= r; i++) {
            int tmp = i-l, pos;
            pos = (tmp+k) % (r-l+1);
            pos = (l+pos) % (r+1);
            if (pos < l) pos += l; 
            aux[pos] = s[i];
        }*/
        
        int len = r-l+1;
        for (int i = 0; i < len; i++) 
            aux[(i+k) % len] = s[i+l];    
        for (int i = l; i <= r; i++)
            s[i] = aux[i-l];
        /*
        for (int i = l; i <= r; i++) 
            s[i] = aux[i];*/
    }
    printf ("%s\n", s);
}


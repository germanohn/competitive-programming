#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll modn = 1000000007;
inline ll mod (ll x) { return x % modn; }

char s[100005];
char p[35];
int fila[100005];

int main () {
    scanf (" %s %s", s, p);
    int cont = 0, k = 0, ini = 0, fim = 0;
    for (int i = 0; s[i] != 0; i++) 
        if (s[i] == p[0]) fila[fim++] = i;
    int tam = strlen (p), mi = 0;
    while (ini != fim) {
        int ind = fila[ini], k = 0;
        if (ind < mi) {
            ini++;
            continue;
        }
        for (int i = ind; k < tam && p[k] == s[i]; i++)
            k++; 
        if (k == tam) cont++, mi = ind+k;
        ini++;
    }
    printf ("%d\n", cont);
}

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

const int MAX = 1000005;

int main () {
    char a[MAX], b[MAX];
    scanf (" %s %s", a, b);
    int ini_a = 0, ini_b = 0, len_a, len_b;
    len_a = strlen (a);
    len_b = strlen (b);
    for (int i = 0; a[i] == '0' && i < len_a; i++) 
        ini_a++;
    for (int i = 0; b[i] == '0' && i < len_b; i++)
        ini_b++;
    int x = len_a-ini_a;
    int y = len_b-ini_b;
    if (x != y) {
        if (x < y) {
            printf ("<\n");
        } else {
            printf (">\n");
        }
    } else {
        while (ini_a < len_a && a[ini_a] == b[ini_b]) 
            ini_a++, ini_b++;
        if (ini_a == len_a) {
            printf ("=\n");
        } else if (a[ini_a] < b[ini_b]) {
            printf ("<\n");
        } else {
            printf (">\n");
        }
    }

}


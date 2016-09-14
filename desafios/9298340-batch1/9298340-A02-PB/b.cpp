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

int mod[55];

int main () {
    char s[55];
    mod[0] = 1, mod[1] = 3;
    for (int i = 2; i <= 50; i++) 
        mod[i] = (mod[i-1]*3) % 7; 
    scanf (" %s", s);
    int ans = 0, len = strlen (s);
    for (int i = 0; s[i] != 0; i++) 
        ans += ((s[i]-'0')*mod[len-1-i]) % 7;
    ans %= 7;
    printf ("%d\n", ans);
}

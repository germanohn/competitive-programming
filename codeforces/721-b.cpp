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

const int MAX = 105;

string s[MAX];
string word;

int main () {
    int n, k;
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }   
    cin >> word;

    int menor = 0, igual = 0;
    int len = word.length ();
    for (int i = 0; i < n; i++) {
        int aux = s[i].length ();
        if (aux < len) menor++;
        else if (aux == len) igual++;
    }
    igual--;
    int ans = 5*(menor/k);
    ans += menor+1;
    printf ("%d ", ans);

    ans = 5*((menor+igual)/k);
    ans += menor+igual+1;
    printf ("%d\n", ans);
}

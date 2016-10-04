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


int main () {
    int format, hour, minu;
    char c, ans[10];
    scanf ("%d %s", &format, ans);
    if (format == 12) {
        if ((ans[0] == '0' && ans[1] == '0') || (ans[0] > '1') || (ans[0] == '1' && ans[1] > '2')) {
            if (ans[0] == '0' && ans[1] == '0') {
                ans[0] = '0', ans[1] = '1';
            } else if (ans[0] > '1') {
                if (ans[1] != '0') ans[0] = '0';
                else ans[0] = '1';
            } else {
                ans[1] = '1';
            }
        }
    } else {
        if ((ans[0] == '2' && ans[1] > '4') || (ans[0] > '2')) {
            ans[0] = '1';
        }
    }

    if (ans[3] > '5') ans[3] = '1';    
    printf ("%s\n", ans);
}


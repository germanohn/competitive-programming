#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// ATENCAO: cuidado com as variaveis dadas no exercicio, nao as reutilize

const int MOD = 1e9 + 7;
const int MAX = 100005;

char s[MAX];
ll freq[MAX];

int val (char c) {
    int val;
    if (c >= '0' && c <= '9') {
        val = c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        val = c - 'A' + 10;  
    } else if (c >= 'a' && c <= 'z') {
        val = c - 'a' + 36;
    } else if (c == '-') {
        val = 62;
    } else if (c == '_') {
        val = 63;
    }
    return val;
}

int main () {
    scanf ("%s", s);
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            freq[i&j]++;
        }
    }
    ll ans = 1;
    for (int i = 0; s[i] != 0; i++) {
        int num = val (s[i]);
        ans = (ans * freq[num]) % MOD;  
    }
    cout << ans << "\n";
}


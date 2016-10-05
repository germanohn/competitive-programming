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

const int MAX = 500005;

char s[MAX];
int freq[MAX];
bool seen[MAX];

int main () {
    scanf (" %s", s);
    int cont = 0, l = 0, r = -1;
    for (int i = 0; s[i] != 0; i++) {
        freq[s[i]]++;
        if (s[i] == '?' || freq[s[i]] == 1) cont++;

        if (i - l + 1 > 26) {
            if (s[l] == '?' || freq[s[l]] == 1) cont--;
            freq[s[l]]--, l++;
        }

        if (cont == 26) {
            r = i;
            break;
        }
    }

    if (r == -1) {
        printf ("-1\n");
    } else {
        for (int i = l; i <= r; i++) {
            if (s[i] != '?') 
                seen[s[i]] = true;
        }

        int k = 'A';
        for (int i = 0; s[i] != 0; i++) {
            if (s[i] != '?') continue;
            if (i < l || i > r) s[i] = 'A';
            else {
                for (; k <= 'Z'; k++) {
                    if (!seen[k]) {
                        s[i] = k++;
                        break;
                    }
                }
            }
        }
        
        printf ("%s\n", s);
    }
}


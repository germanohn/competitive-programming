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

const int MAX = 100005;

char s[MAX];
bool has;

bool arruma (int l) {
    int inc = 1;
    for (int i = l; inc && i >= 0; i--) {
        if (inc) {
            if (s[i] == '9') {
                s[i] = '0';
            } else {
                s[i] = s[i] + '1' - '0';
                inc = 0;
            }
        }
    }

    if (inc) has = true;
}
    
int main () {
    has = false;
    int n, t, st;
    scanf (" %d %d %s", &n, &t, s);
    int len = strlen (s)-1;
    bool f = false;
    for (int i = 0; i <= len; i++) 
        if (s[i] == '.') {
            st = i;
            break;
        }
    while (t > 0) {
        bool change = false;
        for (int i = st; i <= len; i++) {
            if (s[i] > '4') {
                change = true;
                if (len - i + 1 <= t) {
                    // entao posso arredondar
                    t -= (len-i+1);
                    len = i-1;
                    int inc = 1;
                    bool f = true;
                    for (int j = i-1; f && inc && j >= 0; j--) {

                        if (s[j] == '9') {
                            len--;
                            inc = 1;
                        } else {
                            if (s[j] == '.') {
                                if (s[j-1] == '9') arruma (j-1);
                                else {
                                    s[j-1] = s[j-1] + '1' - '0';
                                }
                                len -= 1;
                                break;
                            } else {
                                s[j] = s[j] + '1' - '0';
                                inc = 0;
                                f = false;
                            }
                        }
                    }
                    st = len;
                }
            }
        }
        if (!change) break;
    }
    if (has) printf ("1");
    for (int j = 0; j <= len; j++) 
        printf ("%c", s[j]);
    printf ("\n");
}


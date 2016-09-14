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

char s1[MAX], s2[MAX];
int z[MAX];
bool seen1[MAX], seen2[MAX];

void z_function (char *s, int n) {
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        z[i] = 0;
        if (i > r) {
            l = r = i;
            while (r < n && s[r] == s[r-l]) r++;
            z[i] = r-l, r--;
        } else {
            int k = i-l;
            if (z[k] < r-i+1) z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r] == s[r-l]) r++;
                z[i] = r-l, r--;
            }
        }
    }
}

bool ok (char* s, int len, int n) {
    bool f = true;
    for (int i = len; f && i < n; i++) 
        if (s[i] != s[i%len]) f = false;
    return f;
}

int main () {
    scanf (" %s %s", s1, s2);
    int len_1 = strlen (s1), len_2 = strlen (s2);
    z_function (s1, len_1);
    z[0] = len_1;
    for (int i = 0; s1[i] != 0; i++) {
        if (z[i] != 0 && (len_1 % z[i] == 0) && !seen1[z[i]] && ok (s1, z[i], len_1)) 
            seen1[z[i]] = true;
    }
    z_function (s2, len_2);
    z[0] = len_2;
    for (int i = 0; s2[i] != 0; i++) {
        if (z[i] != 0 && (len_2 % z[i] == 0) && !seen2[z[i]] && ok (s2, z[i], len_2))
            seen2[z[i]] = true;
    }

    int len_common = 0;
    for (int i = 0; i < len_1 && i < len_2; i++) {
        if (s1[i] == s2[i]) len_common++;
        else break;
    }
    int cont = 0;
    int end = min (len_1, len_common);
    for (int i = 1; i <= end; i++) {
        if (seen1[i] && seen2[i]) cont++;
    }

    printf ("%d\n", cont);

}

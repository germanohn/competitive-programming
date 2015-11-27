#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;

char s[MAX], ans[MAX];
int freq[30];

int main () {
    scanf ("%s", s);
    int tam = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i]-'a']++;
        tam++;
    }
    int ini = 0, fim = 26;
    bool b;
    while (ini < fim) {
        b = false;
        if (freq[ini] % 2 == 0) b = true, ini++;
        if (freq[fim] % 2 == 0) b = true, fim--;
        if (!b) {
            freq[ini]++;
            freq[fim]--;
        }
    }
    if (tam % 2 != 0) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                ans[tam/2] = i+'a';
                freq[i]--;
            }
        }
    }
    int i = 0;
    ini = 0, fim = tam-1;
    int f, n = tam-1, q = 26;
    while ((tam % 2 == 0 && i <= q) || (tam % 2 != 0 && i < q)) {
        f = freq[i];
        while (f > 0) {
            ans[ini++] = i+'a';
            ans[fim--] = i+'a';
            f -= 2;
        }
        i++;
    }
    ans[tam] = '\0';
    printf ("%s\n", ans);
}

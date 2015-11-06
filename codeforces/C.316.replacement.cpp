#include <bits/stdc++.h>
using namespace std;

const int MAX = 300005;

int n, m;
char s[MAX];

int main () {
    scanf ("%d %d %s", &n, &m, s);
    int quant = 0, cont = 0, i;
    while (i < n) {
        while (i < n && s[i] == '.') { 
            quant++;
            i++;
        }
        if (quant > 0) cont += quant-1;
        quant = 0;
        i++;
    }
    char c;
    int pos;
    for (int i = 0; i < m; i++) {
        scanf ("%d %c", &pos, &c);
        pos--;
        if (c != '.' && s[pos] != '.') {
            printf ("%d\n", cont);
            continue;
        }
        if (c == '.' && s[pos] == '.') {
            printf ("%d\n", cont);
            continue;
        }
        else if (pos == 0) {
            if (c != '.' && s[pos+1] == '.') 
                cont--;
            else if (c == '.' && s[pos+1] == '.') 
                cont++;
        }
        else if (pos == n-1) { 
            if (c != '.' && s[pos-1] == '.') 
                cont--;
            else if (c == '.' && s[pos-1] == '.') 
                cont++;
        }
        else if (s[pos-1] == '.' && s[pos+1] == '.') {
            if (c != '.') cont -= 2;
            else cont += 2;
        }
        else if ((s[pos-1] == '.' && s[pos+1] != '.') || (s[pos-1] != '.' && s[pos+1] == '.')) {
            if (c != '.') cont--;
            else cont++;
        }
        s[pos] = c;
        printf ("%d\n", cont);
    }
}

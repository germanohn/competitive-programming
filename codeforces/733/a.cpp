#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    char s[105];
    scanf(" %s", s);

    int jump = -1, aux = 0;
    for (int i = 0; s[i] != 0; i++) {
        aux++;
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
            s[i] == 'U' || s[i] == 'Y') {
            if (aux > jump) jump = aux;
            aux = 0;
        }
    }
    if (aux >= jump) jump = aux + 1;

    if (jump != -1) printf("%d\n", jump);
    else printf("%d\n", strlen(s) + 1);
}


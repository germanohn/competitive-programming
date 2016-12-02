#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int seen[500];
char s[105];

int main () {
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) {
        seen[s[i]] = true;
    }

    int cont = 0;
    for (int i = 0; i < 500; i++) {
        if (seen[i]) cont++;
    }

    if (cont % 2 == 0) printf("CHAT WITH HER!\n");
    else printf("IGNORE HIM!\n");
}


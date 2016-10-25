#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[15][15] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main () {
    char s1[15], s2[15];
    int n1, n2;
    scanf (" %s %s", s1, s2);
    for (int i = 0; i < 7; i++) {
        if (strcmp (s1, s[i]) == 0)
            n1 = i;
    }

    for (int i = 0; i < 7; i++) {
        if (strcmp (s2, s[i]) == 0)
            n2 = i;
    }

    int v[5] = {28, 30, 31};
    bool ok = false;

    for (int i = 0; !ok && i < 3; i++) {
        int aux = n1;
        for (int j = 0; j < v[i]; j++) {
            aux = (aux + 1) % 7;
        }
        if (aux == n2) ok = true;
    }

    if (ok) printf ("YES\n");
    else printf ("NO\n");
}


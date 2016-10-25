#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main () {
    char s[20];
    int cont = 0;
    scanf(" %s", s);
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '4' || s[i] == '7')
            cont++;
    }

    bool nearly_lucky;
    if (cont == 0) nearly_lucky = false;
    else nearly_lucky = true;
    while (cont > 0 && nearly_lucky) {
        int a = cont % 10;
        if (a != 4 && a != 7) 
            nearly_lucky = false;

        cont /= 10;
    }

    if (nearly_lucky) printf("YES\n");
    else printf("NO\n");
}


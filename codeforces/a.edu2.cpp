#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int ka, kb, dpspto;
bool ua, ub, haschar, hasld0;
char s[MAX], a[MAX], b[MAX];

int main () {
    scanf ("%s", s);

    ua = ub = 0;
    ka = kb = 0;
    haschar = hasld0 = 0;
    dpspto = 0;
    for (int i = 0; !i || s[i-1] != '\0'; i++) {
        if (s[i] == '\0' || s[i] == ',' || s[i] == ';') {
            if (haschar || (hasld0 && i != dpspto+1) || i == dpspto) {
                if (ub) 
                    b[kb++] = ',';
                for (int j = dpspto; j < i; j++) {
                    b[kb++] = s[j];
                } 
                ub = 1;
            }
            else {
                if (ua) 
                    a[ka++] = ',';
                for (int j = dpspto; j < i; j++) {
                    a[ka++] = s[j];
                }
                ua = 1;
            }

            dpspto = i+1;
            haschar = hasld0 = 0;
        } 
        else if (s[i] < '0' || s[i] > '9') {
            haschar = 1;
        }
        else if (i == dpspto && s[i] == '0')
            hasld0 = 1;
    }
    a[ka++] = b[kb++] = '\0';
    if (ua) printf ("\"%s\"\n", a);
    else printf ("-\n");
    if (ub) printf ("\"%s\"\n", b);
    else printf ("-\n");
}

#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int v[100], aux[100];
char s[100];

int main () {
    scanf ("%d %d  %s", &n, &m, s);
    printf ("%s\n", s); 
    for (int i = 'a'; i <= 'z'; i++) {
        v[i] = i;
        aux[i] = i;
    }
    printf ("%s\n", s);
    for (int i = 0; i < m; i++) {
        scanf (" %d %d", &a, &b);
        int tmp = v[a];
        v[a] = b;
        v[b] = tmp;
    }
    printf ("%s\n", s);
    for (int i = 'a'; i <= 'z'; i++) {
        aux[v[i]] = i;
    }
    printf ("%s\n", s);
    for (int i = 0; s[i] != '\0'; i++)  
        printf ("s %c aux%c", s[i], aux[s[i]]);

    printf ("\n");
}

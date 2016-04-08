#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug (args...) fprintf (stderr, args)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char B[10], E[10];

int main () {   
    char b1, b2, b3, b4;
    char e1, e2, e3, e4;
    scanf (" %c%c %c%c", &b1, &b2, &b3, &b4);
    B[0] = b1, B[1] = b3, B[2] = b4, B[3] = b2;
    scanf (" %c%c %c%c", &e1, &e2, &e3, &e4);
    E[0] = e1, E[1] = e3, E[2] = e4, E[3] = e2;
    int pos;
    for (int i = 0; i < 4; i++) 
        if (E[i] == 'X') 
            pos = i;
    bool f = false;
    int cont = 0; 
    //printf ("%c %c %c %c\n", B[0], B[1], B[2], B[3]);
    for (int i = pos; cont < 4; i++) {
        i %= 4;
        //printf ("%c %c %c %c\n", E[0], E[1], E[2], E[3]);
        if (B[0] == E[0] && B[1] == E[1] && B[2] == E[2] && B[3] == E[3]) {
            f = true;
            break;
        } else {
            int prox = (i+1)%4;
            int aux = E[prox];
            E[prox] = E[i];
            E[i] = aux;
        }
        cont++;
    }
    cont = 0;
    for (int i = pos; cont < 4; i--) {
        if (i < 0) i == 3;
        if (B[0] == E[0] && B[1] == E[1] && B[2] == E[2] && B[3] == E[3]) {
            f = true;
            break;
        } else {
            int prox = i-1;
            if (prox < 0) prox = 3;
            int aux = E[prox];
            E[prox] = E[i];
            E[i] = aux; 
        }
        cont++;
    }
    if (f) printf ("YES\n");
    else printf ("NO\n");
}


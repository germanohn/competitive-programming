#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100005;

char a[MAX], b[MAX], s[MAX], aux[MAX];

int main () {
    scanf (" %s", s);
    bool fa = true, fb = true, ff;
    bool A = false, B = false, esp, ant;
    int af = 0, bf = 0, i = 0;
    int cont = 1;
    while (s[i] != '\0') {
        int k = 0; 
        esp = true;
        A = false, B = false, ff = false, ant = true; 
        while (s[i] != '\0') {
            printf ("s[i] %c\n", s[i]);
            if (s[i] == ',' || s[i] == ';' || s[i] == '.') {
                printf ("sair\n");
                break;
            }
            ant = false;
            aux[k++] = s[i];
            if (!ff && s[i] == '0') {
                ff = true;
                printf ("pri e zero\n");
                esp = false;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                B = true;
                printf ("letra\n");
                esp = false;
            }
            else if (ff && s[i] != '0') {
                B = true;
                printf ("leading\n");
                esp = false;
            }
            i++;
        }
        if (ant) esp = false;
        if (!B && esp) A = true;
        printf ("cont %d aux %s\n", cont, aux);
        /*if (cont == 3) {
        printf ("pri\n");
        return 0;
        }*/
        if (A && esp) {
            if (esp) printf ("espaco true\n");
            if (fa == true) {
                a[0] = '"';
                af++;
                fa = false;
            }
            else {
                a[af] = ',';
                af++;
            }
            for (int j = af; j < af+k; j++) {
                a[j] = aux[j-af];
            } 
            af = af+k;
        }
        else if (B || !esp) {
            if (!esp) printf ("espaco false\n");
            if (fb == true) {
                b[0] = '"';
                bf++;
                fb = false;
            }
            else {
                b[bf] = ',';
                bf++;
            }
            for (int j = bf; j < bf+k; j++) {
                b[j] = aux[j-bf];
            }
            bf = bf+k;
        }
        i++;
        cont++;
    }
    if (strlen (a) > 1) a[af] = '"';
    else a[af] = '-';
    if (strlen (b) > 1) b[bf] = '"';
    else b[bf] = '-';
    printf ("%s\n%s\n", a, b);
}

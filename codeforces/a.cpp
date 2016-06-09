#include<bits/stdc++.h>
using namespace std;

char s[10];
int p[105];

void sieve () {
    for (int i = 2; i < 100; i++) {
        if (!p[i]) {
            for (int j = i*i; j < 100; j += i) 
                p[j] = true;
        }
    }
}

int main () {
    sieve ();
    int v[4] = {2, 3, 5, 7};
    bool prime = true;
    for (int j = 0; j < 4; j++) {
        printf ("%d\n", v[j]);
        fflush (stdout);
        scanf ("%s", s);
        if (s[0] == 'y') {
            int a, b;
            if (prime && j == 0) {
                a = 4, b = 64;
            } else if (prime && j == 1) {
                a = 9, b = 81;
            } else if (prime && j == 2) {
                a = 25, b = 25; 
            } else if (prime && j == 3) {
                a = 49, b = 49;
            }
            if (prime && j >= 0 && j <= 3) {
                for (int i = a; i <= b; i *= a) {
                    printf ("%d\n", i);
                    fflush (stdout);
                    scanf ("%s", s);
                    if (s[0] == 'y') {
                        prime = false;
                        break;
                    }
                    
                }
            }
            if (!prime) 
                break;
            for (int i = v[j]+1; i < 50; i++) {
                if (!p[i]) {
                    printf ("%d\n", i);
                    fflush (stdout);
                    scanf ("%s", s);
                    if (s[0] == 'y') {
                        prime = false;
                        break;
                    }
                }
            }
            break;
        }
    }
    if (prime) 
        printf ("prime\n");
    else 
        printf ("composite\n");
}

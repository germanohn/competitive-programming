#include <bits/stdc++.h>
using namespace std;

char A[10][10];

int main () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf (" %c", &A[i][j]); 
        }
    }
    int b, w, minib = 20, miniw = 20;
    bool f = false;
    for (int i = 0; i < 8 && !f; i++) {
        for (int j = 0; j < 8 && !f; j++) {
            if (A[i][j] == 'W') {
                int l;
                for (l = i-1; l >= 0; l--) {
                    if (A[l][j] == 'B')
                        break;
                }
                if (l == -1) {
                    minib = 7-i;
                    f = true;
                }
            }
        }
    }
    f = false;
    for (int i = 7; i >= 0 && !f; i--) {
        for (int j = 0; j < 8 && !f; j++) {
            if (A[i][j] == 'B') {
                int l;
                for (l = i+1; l < 8; l++) {
                    if (A[l][j] == 'W')
                        break;
                }
                if (l == 8) {
                    miniw = i; 
                    f = true;
                }

            }
        }
    }
    if (minib < miniw) printf ("B\n");
    else printf ("A\n");
}

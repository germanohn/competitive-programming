#include <bits/stdc++.h>
using namespace std;

int t;
int A[10][10];

bool go (int row, int col, int val) {
    for (int j = 1; j <= 9; j++) {
        if (A[row][j] == val) return false;
    }
    for (int i = 1; i <= 9; i++) {
        if (A[i][col] == val) return false;
    }
    for (int i = row; i <= row+3; i++) {
        for (int j = col; j <= col+3; j++) {
            if (A[i][j] == val) return false;
        }
    }
}

void solve () {
    int k = 1; 
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (A[i][j] == 0) {
                if (go (i, j, k)) {
                    A[i][j] = k;
                        
                }
            }
        }
    }
}

int main () {
    scanf ("%d", &t);
    while(t--) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                scanf ("%d", &A[i][j]);
            }
        }
        solve ();
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                printf ("%d", A[i][j]);
            }
            printf ("\n");
        }
    }
}

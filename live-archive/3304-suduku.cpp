#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

char A[MAX][MAX];
int t, grid[MAX][MAX];

bool findEmpty (int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isSafe (int num, int &row, int &col) {
    //row
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == num) 
            return false;
    }
    //col
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num)
            return false;
    }
    //box
    int comI = (row/3)*3;
    int comJ = (col/3)*3;
    for (int i = comI; i < comI+3; i++) {
        for (int j = comJ; j < comJ+3; j++) {
            if (grid[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solveSuduku () {
    int row, col;
    if (!findEmpty (row, col)) 
        return true;
    for (int num = 1; num <= 9; num++) {
        if (isSafe (num, row, col)) {
            grid[row][col] = num;
            if (solveSuduku ())
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main () {
    scanf ("%d", &t);
    while (t--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf (" %c", &A[i][j]);
                grid[i][j] = A[i][j] - '0';
            }
        }
        solveSuduku ();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf ("%d", grid[i][j]);
            }
            printf ("\n");
        }
    }
}

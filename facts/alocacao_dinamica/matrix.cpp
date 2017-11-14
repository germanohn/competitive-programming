#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int **M;
    scanf(" %d %d", &n, &m);
    M = new int*[n];
    for (int i = 0; i < n; i++) 
        M[i] = new int[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &M[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    delete[] M;
    for (int i = 0; i < n; i++)
        delete[] M[i];
}


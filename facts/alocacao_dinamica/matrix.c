#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    int **M;
    M = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < n; i++) {
        M[i] = (int *)malloc(n * sizeof(int));
    }

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

    for (int i = 0; i < n; i++) {
        free(M[i]);
        M[i] = NULL;
    }
    free(M);
    M = NULL;
}


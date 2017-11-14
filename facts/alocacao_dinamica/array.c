#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int *v;
    scanf(" %d", &n);
    v = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }

    int new_size = 2 * n;
    v = (int *)realloc(v, new_size * sizeof(int));

    for (int i = 0; i < new_size; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);
    v = NULL;
}


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int *v;
    scanf(" %d", &n);
    v = new int[n];

    for (int i = 0; i < n; i++) 
        scanf(" %d", &v[i]);

    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    delete[] v;
}


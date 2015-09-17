#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

struct tipo {
    int power, x, y;
};

tipo dup[MAX];
bool paired[805];
int seq[805], n, tam;

bool compare (tipo a, tipo b){
    return a.power > b.power;
}

int main () {
    scanf ("%d", &n);
    int k = 0;
    for (int i = 2; i <= 2 * n; i++) {
        for (int j = 1; j < i; j++) {
            int pto;
            scanf ("%d", &pto);
            dup[k].power = pto;
            dup[k].x = i;
            dup[k].y = j;
            k++;
        }
    }
    for (int i = 1; i <= 2 * n; i++) 
        paired[i] = false;

    sort (dup, dup + k, compare);
    int cont = 2 * n;
    for (int i = 0; i <= k - 1; i++) {
        if (!paired[dup[i].x] && !paired[dup[i].y]) {
            seq[dup[i].x] = dup[i].y;
            paired[dup[i].x] = true;
            seq[dup[i].y] = dup[i].x;
            paired[dup[i].y] = true;
            cont = cont - 2;
        }
        if (cont == 0) break;
    }
    for (int i = 1; i <= 2 * n; i++) 
        printf ("%d ", seq[i]);
    printf ("\n");
}



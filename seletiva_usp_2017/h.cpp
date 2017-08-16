#include<bits/stdc++.h>
using namespace std;

/* N: 0, E: 1, S: 2, O: 3*/

int rotate(int dir, int des) {
    int aux = dir;
    int cont = 0;
    while (aux != des) {
        aux = (aux + 1) % 4;
        cont++;
    }
    return cont;
}

int id(char c) {
    if (c == 'N') return 0;
    else if (c == 'E') return 1;
    else if (c == 'S') return 2;
    return 3;
}

int main() {
    int x0, y0, xd, yd, dir, hor = -1, ver = -1;
    char c;
    scanf(" %d %d %c %d %d", &x0, &y0, &c, &xd, &yd);

    dir = id(c);

    if (x0 - xd < 0) hor = 1;
    else if (x0 - xd > 0) hor = 3;

    if (y0 - yd < 0) ver = 0;
    else if (y0 - yd > 0) ver = 2;

    if (hor == -1 && ver == -1) {
        printf("0\n");
    } else if (hor != -1 && ver == -1) {
        int q = rotate(dir, hor);
        printf("%d\n", q + 1);
        while (q--) printf("D\n");
        printf("A %d\n", abs(x0 - xd));
    } else if (hor == -1 && ver != -1) {
        int q = rotate(dir, ver);
        printf("%d\n", q + 1);
        while (q--) printf("D\n");
        printf("A %d\n", abs(y0 - yd));
    } else {
        int q = max(rotate(dir, ver), rotate(dir, hor));
        printf("%d\n", q + 2);
        q = min(rotate(dir, ver), rotate(dir, hor));
        dir = (dir + q) % 4;
        while (q--) printf("D\n");
        if (dir == hor) printf("A %d\n", abs(x0 - xd));
        else printf("A %d\n", abs(y0 - yd));

        q = max(rotate(dir, ver), rotate(dir, hor));
        dir = (dir + q) % 4;
        while (q--) printf("D\n");
        if (dir == hor) printf("A %d\n", abs(x0 - xd));
        else printf("A %d\n", abs(y0 - yd));
    }
}

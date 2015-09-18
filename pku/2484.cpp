#include <cstdio>

int main () {
    int n;
    while (scanf ("%d", &n) && n != 0) {
        if (n <= 2) printf ("Alice\n");
        else printf ("Bob\n");
    }
}

